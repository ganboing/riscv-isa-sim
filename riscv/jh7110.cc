#include <sys/time.h>
#include <sstream>
#include "devices.h"
#include "processor.h"
#include "term.h"
#include "sim.h"
#include "dts.h"
#include "libfdt.h"
#include "jh7110.h"

static uint32_t jh7110_aon_crg_regs[JH7110_AON_RESET_ASSERT] = {

};

static uint32_t jh7110_aon_crg_reset = 0xffffffff;

jh7110_aon_crg_t::jh7110_aon_crg_t() {
  jh7110_aon_crg_regs[JH7110_OSC_DIV4] = 4;
  jh7110_aon_crg_regs[JH7110_OTPC_CLK_APB] = 0x80000000;
}

bool jh7110_aon_crg_t::load(reg_t addr, size_t len, uint8_t* bytes) {
  if (len != 4) {
    fprintf(stderr, "%s: invalid read of jh7110_aon_crg, size != 4\n", __PRETTY_FUNCTION__);
    return false;
  }
  switch (addr / 4) {
    case JH7110_OSC_DIV4:
    case JH7110_OTPC_CLK_APB:
      memcpy(bytes, &jh7110_aon_crg_regs[addr / 4], 4);
      fprintf(stderr, "%s: reading %s, returning %x\n", __PRETTY_FUNCTION__,
              jh7110_aon_crg_reg_names[addr / 4], *(uint32_t*)bytes);
      break;
    case JH7110_AON_RESET_ASSERT:
      memcpy(bytes, &jh7110_aon_crg_reset, 4);
      fprintf(stderr, "%s: reading %s, returning %x\n", __PRETTY_FUNCTION__,
              jh7110_aon_crg_reg_names[addr / 4], *(uint32_t*)bytes);
      break;
    case JH7110_AON_RESET_STATUS: {
      uint32_t inverted = ~jh7110_aon_crg_reset;
      memcpy(bytes, &inverted, 4);
      fprintf(stderr, "%s: reading %s, returning %x\n", __PRETTY_FUNCTION__,
              jh7110_aon_crg_reg_names[addr / 4], *(uint32_t*)bytes);
      break;
    }
    default:
      fprintf(stderr, "%s: unknown read of jh7110_aon_crg, off=%lx\n", __PRETTY_FUNCTION__, addr);
      for(;;);
  }
  return true;
}

bool jh7110_aon_crg_t::store(reg_t addr, size_t len, const uint8_t* bytes) {
  if (len != 4) {
    fprintf(stderr, "%s: invalid write of jh7110_aon_crg, size != 4", __PRETTY_FUNCTION__);
    return false;
  }
  switch (addr / 4) {
    case JH7110_OSC_DIV4:
    case JH7110_OTPC_CLK_APB:
      memcpy(&jh7110_aon_crg_regs[addr / 4], bytes, 4);
      fprintf(stderr, "%s: setting %s to %x\n", __PRETTY_FUNCTION__,
              jh7110_aon_crg_reg_names[addr / 4], *(uint32_t*)bytes);
      break;
    case JH7110_AON_RESET_ASSERT:
      memcpy(&jh7110_aon_crg_reset, bytes, 4);
      fprintf(stderr, "%s: setting %s to %x\n", __PRETTY_FUNCTION__,
              jh7110_aon_crg_reg_names[addr / 4], *(uint32_t*)bytes);
      break;
    default:
      fprintf(stderr, "%s: unknown write of jh7110_aon_crg, off=%lx\n", __PRETTY_FUNCTION__, addr);
      for(;;);
  }
  return true;
}

std::string jh7110_aon_crg_generate_dts(const sim_t* sim)
{
  std::stringstream s;
  s << std::hex
    << "    JH7110_AON_CRG: @" << JH7110_AON_CRG_BASE << " {\n"
       "      compatible = \"jh7110_aon_crg\";\n" <<
       "      reg = <0x0 0x" << (JH7110_AON_CRG_BASE) <<
                   " 0x0 0x" << (JH7110_AON_CRG_SIZE) << ">;\n"
       "    };\n";
  return s.str();
}

jh7110_aon_crg_t* jh7110_aon_crg_parse_from_fdt(const void* fdt, const sim_t* sim, reg_t* base)
{

  int nodeoffset, len, rc;
  unsigned long sz;
  const fdt32_t *reg_p;
  uint32_t intr_id;

  nodeoffset = fdt_node_offset_by_compatible(fdt, -1, "jh7110_aon_crg");
  if (nodeoffset < 0)
    return nullptr;

  rc = fdt_get_node_addr_size(fdt, nodeoffset, base, &sz, "reg");
  if (rc < 0)
    return nullptr;

  return new jh7110_aon_crg_t();
}

REGISTER_DEVICE(jh7110_aon_crg, jh7110_aon_crg_parse_from_fdt, jh7110_aon_crg_generate_dts);
/* ======================================================================================================================== */

jh7110_aon_iomux_t::jh7110_aon_iomux_t() {}

uint32_t RGPIO_PADCFG[4] = {1, 1, 1, 1};
uint32_t JH7110_BOOT_MODE = [](){
  const char *jh7110_bootmode = getenv("JH7110_BOOTMODE");
  if (!jh7110_bootmode) {
      return 3; // UART mode
  }
  if (!strcmp(jh7110_bootmode, "flash")) {
      return 0;
  } else if (!strcmp(jh7110_bootmode, "sdcard")) {
      return 1;
  } else if (!strcmp(jh7110_bootmode, "emmc")) {
      return 2;
  } else if (!strcmp(jh7110_bootmode, "uart")) {
      return 3;
  }
  return 3;
}() | 4;

bool jh7110_aon_iomux_t::load(reg_t addr, size_t len, uint8_t* bytes) {
  if (len != 4) {
    fprintf(stderr, "%s: invalid read of jh7110_aon_iomux, size != 4\n", __PRETTY_FUNCTION__);
    return false;
  }
  switch (addr) {
    case 0x0c:
      fprintf(stderr, "%s: returning 0 for EN_0\n", __PRETTY_FUNCTION__);
      memset(bytes, 0, 4);
      break;
    case 0x2c:
      memcpy(bytes, &JH7110_BOOT_MODE, 4);
      fprintf(stderr, "%s: reading boot mode %x\n", __PRETTY_FUNCTION__, *(uint32_t*)bytes);
      break;
    case 0x34 ... 0x40: {
      unsigned idx = (addr - 0x34) / 4;
      memcpy(bytes, &RGPIO_PADCFG[idx], 4);
      fprintf(stderr, "%s: reading RGPIO%u, returning %x\n", __PRETTY_FUNCTION__, idx, *(uint32_t*)bytes);
      break;
    }
    default:
      fprintf(stderr, "%s: unknown read of jh7110_aon_iomux, off=%lx\n", __PRETTY_FUNCTION__, addr);
      for(;;);
  }
  return true;
}

bool jh7110_aon_iomux_t::store(reg_t addr, size_t len, const uint8_t* bytes) {
  if (len != 4) {
    fprintf(stderr, "%s: invalid write of jh7110_aon_iomux, size != 4", __PRETTY_FUNCTION__);
    return false;
  }
  switch (addr) {
    case 0x0c:
      fprintf(stderr, "%s: setting EN_0 to %x\n", __PRETTY_FUNCTION__, *(uint32_t*)bytes);
      break;
    case 0x34 ... 0x40: {
      unsigned idx = (addr - 0x34) / 4;
      memcpy(&RGPIO_PADCFG[idx], bytes, 4);
      fprintf(stderr, "%s: setting RGPIO%u to %x\n", __PRETTY_FUNCTION__, idx, *(uint32_t*)bytes);
      break;
    }
    default:
      fprintf(stderr, "%s: unknown write of jh7110_aon_iomux, off=%lx\n", __PRETTY_FUNCTION__, addr);
      for(;;);
  }
  return true;
}

std::string jh7110_aon_iomux_generate_dts(const sim_t* sim)
{
  std::stringstream s;
  s << std::hex
    << "    JH7110_AON_IOMUX: @" << JH7110_AON_IOMUX_BASE << " {\n"
       "      compatible = \"jh7110_aon_iomux\";\n" <<
       "      reg = <0x0 0x" << (JH7110_AON_IOMUX_BASE) <<
                   " 0x0 0x" << (JH7110_AON_IOMUX_SIZE) << ">;\n"
       "    };\n";
  return s.str();
}

jh7110_aon_iomux_t* jh7110_aon_iomux_parse_from_fdt(const void* fdt, const sim_t* sim, reg_t* base)
{

  int nodeoffset, len, rc;
  unsigned long sz;
  const fdt32_t *reg_p;
  uint32_t intr_id;

  nodeoffset = fdt_node_offset_by_compatible(fdt, -1, "jh7110_aon_iomux");
  if (nodeoffset < 0)
    return nullptr;

  rc = fdt_get_node_addr_size(fdt, nodeoffset, base, &sz, "reg");
  if (rc < 0)
    return nullptr;

  return new jh7110_aon_iomux_t();
}

REGISTER_DEVICE(jh7110_aon_iomux, jh7110_aon_iomux_parse_from_fdt, jh7110_aon_iomux_generate_dts);
/* ======================================================================================================================== */

static uint32_t jh7110_sys_crg_regs[JH7110_SYSCRG_RESET_ASSERT0] = {

};

static uint32_t jh7110_sys_crg_resets[4] = {
    0xffffffff,
    0xffffffff,
    0xffffffff,
    0xffffffff,
};

jh7110_sys_crg_t::jh7110_sys_crg_t(){
  jh7110_sys_crg_regs[JH7110_PLL0_DIV2] = 2;
  jh7110_sys_crg_regs[JH7110_PLL1_DIV2] = 2;
  jh7110_sys_crg_regs[JH7110_PLL2_DIV2] = 2;
  jh7110_sys_crg_regs[JH7110_AHB0] = 0x80000000;
  jh7110_sys_crg_regs[JH7110_AHB1] = 0x80000000;
  jh7110_sys_crg_regs[JH7110_APB0] = 0x80000000;
  jh7110_sys_crg_regs[JH7110_UART0_CLK_APB] = 0x80000000;
  jh7110_sys_crg_regs[JH7110_UART0_CLK_CORE] = 0x80000000;
  jh7110_sys_crg_regs[JH7110_BUS_ROOT] = 0; // By default we are using OSC (24Mhz)
  jh7110_sys_crg_regs[JH7110_SDIO0_CLK_AHB] = 0x80000000;
  jh7110_sys_crg_regs[JH7110_SDIO1_CLK_AHB] = 0x80000000;
  jh7110_sys_crg_regs[JH7110_SDIO0_CLK_SDCARD] = 0x80000002;
  jh7110_sys_crg_regs[JH7110_SDIO1_CLK_SDCARD] = 0x80000002;
}

bool jh7110_sys_crg_t::load(reg_t addr, size_t len, uint8_t* bytes) {
  if (len != 4) {
    fprintf(stderr, "%s: invalid read of jh7110_sys_crg, size != 4\n", __PRETTY_FUNCTION__);
    return false;
  }
  switch (addr / 4) {
    case JH7110_APB0:
    case JH7110_AHB0:
    case JH7110_PLL0_DIV2:
    case JH7110_PLL1_DIV2:
    case JH7110_PLL2_DIV2:
    case JH7110_UART0_CLK_APB:
    case JH7110_UART0_CLK_CORE:
    case JH7110_BUS_ROOT:
    case JH7110_SDIO0_CLK_AHB:
    case JH7110_SDIO1_CLK_AHB:
    case JH7110_SDIO0_CLK_SDCARD:
    case JH7110_SDIO1_CLK_SDCARD:
      memcpy(bytes, &jh7110_sys_crg_regs[addr / 4], 4);
      fprintf(stderr, "%s: reading %s, returning %x\n", __PRETTY_FUNCTION__,
              jh7110_sys_crg_reg_names[addr / 4], *(uint32_t*)bytes);
      break;
    case JH7110_SYSCRG_RESET_ASSERT0 ... JH7110_SYSCRG_RESET_ASSERT3:
      memcpy(bytes, &jh7110_sys_crg_resets[addr / 4 - JH7110_SYSCRG_RESET_ASSERT0], 4);
      fprintf(stderr, "%s: reading %s, returning %x\n", __PRETTY_FUNCTION__,
              jh7110_sys_crg_reg_names[addr / 4], *(uint32_t*)bytes);
      break;
    case JH7110_SYSCRG_RESET_STATUS0 ... JH7110_SYSCRG_RESET_STATUS3: {
      uint32_t inverted = ~jh7110_sys_crg_resets[addr / 4 - JH7110_SYSCRG_RESET_STATUS0];
      memcpy(bytes, &inverted, 4);
      fprintf(stderr, "%s: reading %s, returning %x\n", __PRETTY_FUNCTION__,
              jh7110_sys_crg_reg_names[addr / 4], *(uint32_t*)bytes);
      break;
    }
    default:
      fprintf(stderr, "%s: unknown read of jh7110_sys_crg, off=%lx\n", __PRETTY_FUNCTION__, addr);
      for(;;);
  }
  return true;
}

bool jh7110_sys_crg_t::store(reg_t addr, size_t len, const uint8_t* bytes) {
  if (len != 4) {
    fprintf(stderr, "%s: invalid write of jh7110_sys_crg, size != 4", __PRETTY_FUNCTION__);
    return false;
  }
  switch (addr / 4) {
    case JH7110_APB0:
    case JH7110_AHB0:
    case JH7110_PLL0_DIV2:
    case JH7110_PLL1_DIV2:
    case JH7110_PLL2_DIV2:
    case JH7110_UART0_CLK_APB:
    case JH7110_UART0_CLK_CORE:
    case JH7110_BUS_ROOT:
    case JH7110_SDIO0_CLK_AHB:
    case JH7110_SDIO1_CLK_AHB:
    case JH7110_SDIO0_CLK_SDCARD:
    case JH7110_SDIO1_CLK_SDCARD:
      memcpy(&jh7110_sys_crg_regs[addr / 4], bytes, 4);
      fprintf(stderr, "%s: setting %s to %x\n", __PRETTY_FUNCTION__,
              jh7110_sys_crg_reg_names[addr / 4], *(uint32_t*)bytes);
      break;
    case JH7110_SYSCRG_RESET_ASSERT0 ... JH7110_SYSCRG_RESET_ASSERT3: {
      uint32_t newval = *(uint32_t*)bytes;
      uint32_t changed = jh7110_sys_crg_resets[addr / 4 - JH7110_SYSCRG_RESET_ASSERT0] ^ newval;
      jh7110_sys_crg_resets[addr / 4 - JH7110_SYSCRG_RESET_ASSERT0] = newval;
      while (changed) {
        int bit = __builtin_ffsl(changed) - 1;
        reg_t reset = (addr / 4 - JH7110_SYSCRG_RESET_ASSERT0) * 32 + bit;
        bool asserted = newval & (1U << bit);

        changed ^= (1UL << bit);
        fprintf(stderr, "%s: %sasserting %s\n", __PRETTY_FUNCTION__,
                asserted ? "" : "de", jh7110_sys_crg_reset_names[reset]);
      }
      fprintf(stderr, "%s: setting %s to %x\n", __PRETTY_FUNCTION__,
              jh7110_sys_crg_reg_names[addr / 4], *(uint32_t*)bytes);
      break;
    }
    default:
      fprintf(stderr, "%s: unknown write of jh7110_sys_crg, off=%lx\n", __PRETTY_FUNCTION__, addr);
      for(;;);
  }
  return true;
}

std::string jh7110_sys_crg_generate_dts(const sim_t* sim)
{
  std::stringstream s;
  s << std::hex
    << "    JH7110_SYS_CRG: @" << JH7110_SYS_CRG_BASE << " {\n"
       "      compatible = \"jh7110_sys_crg\";\n" <<
       "      reg = <0x0 0x" << (JH7110_SYS_CRG_BASE) <<
                   " 0x0 0x" << (JH7110_SYS_CRG_SIZE) << ">;\n"
       "    };\n";
  return s.str();
}

jh7110_sys_crg_t* jh7110_sys_crg_parse_from_fdt(const void* fdt, const sim_t* sim, reg_t* base)
{

  int nodeoffset, len, rc;
  unsigned long sz;
  const fdt32_t *reg_p;
  uint32_t intr_id;

  nodeoffset = fdt_node_offset_by_compatible(fdt, -1, "jh7110_sys_crg");
  if (nodeoffset < 0)
    return nullptr;

  rc = fdt_get_node_addr_size(fdt, nodeoffset, base, &sz, "reg");
  if (rc < 0)
    return nullptr;

  return new jh7110_sys_crg_t();
}

REGISTER_DEVICE(jh7110_sys_crg, jh7110_sys_crg_parse_from_fdt, jh7110_sys_crg_generate_dts);
/* ======================================================================================================================== */

static uint32_t jh7110_sys_iomux_den[16] = {
        JH7110_IOMUX_DEN_GROUP( H,  H,  H,  8), //00-03  U0_JTAG_TRSTN(IN)/TCK(IN)/TDI(IN)/TDOEN
        JH7110_IOMUX_DEN_GROUP( H, __,  H, __), //04-07  U0_JTAG_TMS(IN) U0_DW_UART_SOUT/SIN(IN)
        JH7110_IOMUX_DEN_GROUP(__,  H,  H,  7), //08-11  U0_HIFI4_JTCK(IN)/TDI(IN)/TDOEN
        JH7110_IOMUX_DEN_GROUP( H,  H, __, __), //12-15  U0_HIFI4_JTMS(IN)/TRSTN(IN)
        JH7110_IOMUX_DEN_GROUP(__, __, __,  H), //16-19  U3_DW_UART_SOUT/SIN(IN)
        JH7110_IOMUX_DEN_GROUP(__, __, __, __), //20-23
        JH7110_IOMUX_DEN_GROUP(__, __, __, __), //24-27
        JH7110_IOMUX_DEN_GROUP(__, __, __, __), //28-31
        JH7110_IOMUX_DEN_GROUP(__, __, __, __), //32-35
        JH7110_IOMUX_DEN_GROUP( 5,  6, 34, 35), //36-39  U0_DW_I2C/U3_DW_I2C
        JH7110_IOMUX_DEN_GROUP( H, __, __,  H), //40-43  U2_DW_UART (IN)
        JH7110_IOMUX_DEN_GROUP( H, __, __,  H), //44-47  U4_DW_UART (IN)
        JH7110_IOMUX_DEN_GROUP(13, 13,  H, 14), //48-51  U0_SSP_SPI
        JH7110_IOMUX_DEN_GROUP(28, 28,  H, 29), //52-55  U1_SSP_SPI
        JH7110_IOMUX_DEN_GROUP(36, 36,  H, 37), //56-59  U3_SSP_SPI
        JH7110_IOMUX_DEN_GROUP(40, 40,  H, 41), //60-63  U4_SSP_SPI
};

static uint32_t jh7110_sys_iomux_dout[16] = {
        JH7110_IOMUX_DOUT_GROUP(__, __, __, 22), //00-03  U0_JTAG_CERTIFICATION_TDO
        JH7110_IOMUX_DOUT_GROUP(__, 20, __, __), //04-07  U0_DW_UART_SOUT
        JH7110_IOMUX_DOUT_GROUP(__, __, __, 21), //08-11  U0_HIFI4_JTDO
        JH7110_IOMUX_DOUT_GROUP(__, __, __, __), //12-15
        JH7110_IOMUX_DOUT_GROUP(__, __, 85, __), //16-19  U3_DW_UART_SOUT
        JH7110_IOMUX_DOUT_GROUP(__, __, __, __), //20-23
        JH7110_IOMUX_DOUT_GROUP(__, __, __, __), //24-27
        JH7110_IOMUX_DOUT_GROUP(__, __, __, __), //28-31
        JH7110_IOMUX_DOUT_GROUP(__, __, __, 13), //32-35  U0_DSKIT_WDT_WDOGRES
        JH7110_IOMUX_DOUT_GROUP(14, 15, 83, 84), //36-39  U0_DW_I2C/U3_DW_I2C
        JH7110_IOMUX_DOUT_GROUP(__, 79, 78, __), //40-43  U2_DW_UART
        JH7110_IOMUX_DOUT_GROUP(__, 92, 91, __), //44-47  U4_DW_UART
        JH7110_IOMUX_DOUT_GROUP(31, 30, __, 32), //48-51  U0_SSP_SPI
        JH7110_IOMUX_DOUT_GROUP(74, 73, __, 75), //52-55  U1_SSP_SPI
        JH7110_IOMUX_DOUT_GROUP(87, 86, __, 88), //56-59  U3_SSP_SPI
        JH7110_IOMUX_DOUT_GROUP(94, 93, __, 95), //60-63  U4_SSP_SPI
};

static uint32_t jh7110_sys_iomux_din[23] = {
        JH7110_IOMUX_DIN_GROUP(XX, XX, XX, XX), //00-03
        JH7110_IOMUX_DIN_GROUP( 0, XX, XX, XX), //04-07  U0_CLKRST_SRC_BYPASS_JTAG_TRSTN
        JH7110_IOMUX_DIN_GROUP(XX, 36, 37, XX), //08-11  U0_DW_I2C_IC_CLK_IN_A/DATA_IN_A
        JH7110_IOMUX_DIN_GROUP(XX, XX,  6,  9), //12-15  U0_DW_UART_SIN U0_HIFI4_JTCK
        JH7110_IOMUX_DIN_GROUP(10, 12, 13,  2), //16-19  U0_HIFI4_JTDI/JTMS/JTRSTN U0_JTAG_CERTIFICATION_TDI
        JH7110_IOMUX_DIN_GROUP( 4, XX, XX, XX), //20-23  U0_JTAG_CERTIFICATION_TMS
        JH7110_IOMUX_DIN_GROUP(XX, XX, 49, 48), //24-27  U0_SSP_SPI_SSPCLKIN/FSSIN
        JH7110_IOMUX_DIN_GROUP(50,  1, XX, XX), //28-31  U0_SSP_SPI_SSPRXD U0_SYS_CRG_CLK_JTAG_TCK
        JH7110_IOMUX_DIN_GROUP(XX, XX, XX, XX), //32-35
        JH7110_IOMUX_DIN_GROUP(XX, XX, XX, XX), //36-39
        JH7110_IOMUX_DIN_GROUP(XX, XX, XX, XX), //40-43
        JH7110_IOMUX_DIN_GROUP(XX, XX, XX, XX), //44-47
        JH7110_IOMUX_DIN_GROUP(XX, XX, XX, XX), //48-51
        JH7110_IOMUX_DIN_GROUP(XX, XX, XX, XX), //52-55
        JH7110_IOMUX_DIN_GROUP(53, 52, 54, XX), //56-59  U1_SSP_SPI_SSPCLKIN/FSSIN/RXD
        JH7110_IOMUX_DIN_GROUP(XX, 43, 40, XX), //60-63  U2_DW_UART_CTS_N/SIN
        JH7110_IOMUX_DIN_GROUP(XX, XX, 38, 39), //64-67  U3_DW_I2C_IC_CLK_IN_A/DATA_IN_A
        JH7110_IOMUX_DIN_GROUP(19, 57, 56, 58), //68-71  U3_DW_UART_SIN U3_SSP_SPI_SSPCLKIN/FSSIN/RXD
        JH7110_IOMUX_DIN_GROUP(XX, XX, 47, 44), //72-75  U4_DW_UART_CTS_N/SIN
        JH7110_IOMUX_DIN_GROUP(61, 60, 62, XX), //76-79  U4_SSP_SPI_SSPCLKIN/FSSIN/RXD
        JH7110_IOMUX_DIN_GROUP(XX, XX, XX, XX), //80-83
        JH7110_IOMUX_DIN_GROUP(XX, XX, XX, XX), //84-87
        JH7110_IOMUX_DIN_GROUP(XX, XX, XX, XX), //88-91
};

jh7110_sys_iomux_t::jh7110_sys_iomux_t(){}

bool jh7110_sys_iomux_t::load(reg_t addr, size_t len, uint8_t* bytes) {
  if (len != 4) {
    fprintf(stderr, "%s: invalid read of jh7110_sys_iomux, size != 4\n", __PRETTY_FUNCTION__);
    return false;
  }
  switch (addr / 4) {
    case 0 ... 0xf:
      memcpy(bytes, &jh7110_sys_iomux_den[addr / 4], 4);
      fprintf(stderr, "%s: reading den%u, returning %x\n", __PRETTY_FUNCTION__,
              (unsigned)addr / 4, *(uint32_t*)bytes);
      break;
    case 0x10 ... 0x1f:
      memcpy(bytes, &jh7110_sys_iomux_dout[addr / 4 - 0x10], 4);
      fprintf(stderr, "%s: reading dout%u, returning %x\n", __PRETTY_FUNCTION__,
              (unsigned)(addr / 4 - 0x10), *(uint32_t*)bytes);
      break;
    case 0x20 ... 0x36:
      memcpy(bytes, &jh7110_sys_iomux_din[addr / 4 - 0x20], 4);
      fprintf(stderr, "%s: reading din%u, returning %x\n", __PRETTY_FUNCTION__,
              (unsigned)(addr / 4 - 0x20), *(uint32_t*)bytes);
      break;
    default:
      fprintf(stderr, "%s: unknown read of jh7110_sys_iomux, off=%lx\n", __PRETTY_FUNCTION__, addr);
      for(;;);
  }
  return true;
}

bool jh7110_sys_iomux_t::store(reg_t addr, size_t len, const uint8_t* bytes) {
  if (len != 4) {
    fprintf(stderr, "%s: invalid write of jh7110_sys_iomux, size != 4", __PRETTY_FUNCTION__);
    return false;
  }
  switch (addr / 4) {
    case 0 ... 0xf:
      memcpy(&jh7110_sys_iomux_den[addr / 4], bytes, 4);
      fprintf(stderr, "%s: setting den%u to %x\n", __PRETTY_FUNCTION__,
              (unsigned)addr / 4, *(uint32_t*)bytes);
      break;
    case 0x10 ... 0x1f:
      memcpy(&jh7110_sys_iomux_dout[addr / 4 - 0x10], bytes, 4);
      fprintf(stderr, "%s: setting dout%u to %x\n", __PRETTY_FUNCTION__,
              (unsigned)(addr / 4 - 0x10), *(uint32_t*)bytes);
      break;
    case 0x20 ... 0x36:
      memcpy(&jh7110_sys_iomux_din[addr / 4 - 0x20], bytes, 4);
      fprintf(stderr, "%s: setting din%u to %x\n", __PRETTY_FUNCTION__,
              (unsigned)(addr / 4 - 0x20), *(uint32_t*)bytes);
      break;
    default:
      fprintf(stderr, "%s: unknown write of jh7110_sys_iomux, off=%lx\n", __PRETTY_FUNCTION__, addr);
      for(;;);
  }
  return true;
}

std::string jh7110_sys_iomux_generate_dts(const sim_t* sim)
{
  std::stringstream s;
  s << std::hex
    << "    JH7110_SYS_IOMUX: @" << JH7110_SYS_IOMUX_BASE << " {\n"
       "      compatible = \"jh7110_sys_iomux\";\n" <<
       "      reg = <0x0 0x" << (JH7110_SYS_IOMUX_BASE) <<
                   " 0x0 0x" << (JH7110_SYS_IOMUX_SIZE) << ">;\n"
       "    };\n";
  return s.str();
}

jh7110_sys_iomux_t* jh7110_sys_iomux_parse_from_fdt(const void* fdt, const sim_t* sim, reg_t* base)
{

  int nodeoffset, len, rc;
  unsigned long sz;
  const fdt32_t *reg_p;
  uint32_t intr_id;

  nodeoffset = fdt_node_offset_by_compatible(fdt, -1, "jh7110_sys_iomux");
  if (nodeoffset < 0)
    return nullptr;

  rc = fdt_get_node_addr_size(fdt, nodeoffset, base, &sz, "reg");
  if (rc < 0)
    return nullptr;

  return new jh7110_sys_iomux_t();
}

REGISTER_DEVICE(jh7110_sys_iomux, jh7110_sys_iomux_parse_from_fdt, jh7110_sys_iomux_generate_dts);
/* ======================================================================================================================== */

uint32_t jh7110_otp_busy_count = 0;

jh7110_otp_t::jh7110_otp_t(){}

bool jh7110_otp_t::load(reg_t addr, size_t len, uint8_t* bytes) {
  if (len != 4) {
    fprintf(stderr, "%s: invalid read of jh7110_otp, size != 4\n", __PRETTY_FUNCTION__);
    return false;
  }
  switch (addr / 4) {
    case JH7110_OTP_SR: {
      uint32_t ret = 0;
      if (jh7110_otp_busy_count) {
          ret |= 0x80000000;
          --jh7110_otp_busy_count;
      }
      memcpy(bytes, &ret, 4);
      fprintf(stderr, "%s: returning %x for OTP_SR, busy count=%u\n", __PRETTY_FUNCTION__, ret, jh7110_otp_busy_count);
      break;
    }
    case 0x800 / 4 ... 0x1000 / 4 - 1:
      memset(bytes, 0xff, 4);
      fprintf(stderr, "%s: returning %x for all OTP read, off=%lx\n", __PRETTY_FUNCTION__, *(uint32_t*)bytes, addr - 0x800);
      break;
    default:
      fprintf(stderr, "%s: unknown read of jh7110_otp, off=%lx\n", __PRETTY_FUNCTION__, addr);
      for(;;);
  }
  return true;
}

bool jh7110_otp_t::store(reg_t addr, size_t len, const uint8_t* bytes) {
  if (len != 4) {
    fprintf(stderr, "%s: invalid write of jh7110_otp, size != 4", __PRETTY_FUNCTION__);
    return false;
  }
  switch (addr / 4) {
    case JH7110_OTP_CFG:
      fprintf(stderr, "%s: ignoring write to OTP_CFG, val=%x\n", __PRETTY_FUNCTION__, *(uint32_t*)bytes);
      break;
    case JH7110_OTP_OPR:
      jh7110_otp_busy_count += 3;
      fprintf(stderr, "%s: setting OTP_OPR to %x, ignored. setting busy cout %u\n", __PRETTY_FUNCTION__,
              *(uint32_t*)bytes, jh7110_otp_busy_count);
      break;
    default:
      fprintf(stderr, "%s: unknown write of jh7110_otp, off=%lx, val=%x\n", __PRETTY_FUNCTION__,
              addr, *(uint32_t*)bytes);
      for(;;);
  }
  return true;
}

std::string jh7110_otp_generate_dts(const sim_t* sim)
{
  std::stringstream s;
  s << std::hex
    << "    JH7110_OTP: @" << JH7110_OTP_BASE << " {\n"
       "      compatible = \"jh7110_otp\";\n" <<
       "      reg = <0x0 0x" << (JH7110_OTP_BASE) <<
                   " 0x0 0x" << (JH7110_OTP_SIZE) << ">;\n"
       "    };\n";
  return s.str();
}

jh7110_otp_t* jh7110_otp_parse_from_fdt(const void* fdt, const sim_t* sim, reg_t* base)
{

  int nodeoffset, len, rc;
  unsigned long sz;
  const fdt32_t *reg_p;
  uint32_t intr_id;

  nodeoffset = fdt_node_offset_by_compatible(fdt, -1, "jh7110_otp");
  if (nodeoffset < 0)
    return nullptr;

  rc = fdt_get_node_addr_size(fdt, nodeoffset, base, &sz, "reg");
  if (rc < 0)
    return nullptr;

  return new jh7110_otp_t();
}

REGISTER_DEVICE(jh7110_otp, jh7110_otp_parse_from_fdt, jh7110_otp_generate_dts);
