#ifndef __JH7110_H__
#define __JH7110_H__

/* sys regisger */
#define JH7110_CPU_ROOT                        0
#define JH7110_CPU_CORE                        1
#define JH7110_CPU_BUS                         2
#define JH7110_GPU_ROOT                        3
#define JH7110_PERH_ROOT                       4
#define JH7110_BUS_ROOT                        5
#define JH7110_NOCSTG_BUS                      6
#define JH7110_AXI_CFG0                        7
#define JH7110_STG_AXIAHB                      8
#define JH7110_AHB0                            9
#define JH7110_AHB1                            10
#define JH7110_APB_BUS_FUNC                    11
#define JH7110_APB0                            12
#define JH7110_PLL0_DIV2                       13
#define JH7110_PLL1_DIV2                       14
#define JH7110_PLL2_DIV2                       15
#define JH7110_AUDIO_ROOT                      16
#define JH7110_MCLK_INNER                      17
#define JH7110_MCLK                            18
#define JH7110_MCLK_OUT                        19
#define JH7110_ISP_2X                          20
#define JH7110_ISP_AXI                         21
#define JH7110_GCLK0                           22
#define JH7110_GCLK1                           23
#define JH7110_GCLK2                           24
#define JH7110_U7_CORE_CLK                     25
#define JH7110_U7_CORE_CLK1                    26
#define JH7110_U7_CORE_CLK2                    27
#define JH7110_U7_CORE_CLK3                    28
#define JH7110_U7_CORE_CLK4                    29
#define JH7110_U7_DEBUG_CLK                    30
#define JH7110_U7_RTC_TOGGLE                   31
#define JH7110_U7_TRACE_CLK0                   32
#define JH7110_U7_TRACE_CLK1                   33
#define JH7110_U7_TRACE_CLK2                   34
#define JH7110_U7_TRACE_CLK3                   35
#define JH7110_U7_TRACE_CLK4                   36
#define JH7110_U7_TRACE_COM_CLK                37
#define JH7110_NOC_BUS_CLK_CPU_AXI             38
#define JH7110_NOC_BUS_CLK_AXICFG0_AXI         39
#define JH7110_OSC_DIV2                        40
#define JH7110_PLL1_DIV4                       41
#define JH7110_PLL1_DIV8                       42
#define JH7110_DDR_BUS                         43
#define JH7110_DDR_CLK_AXI                     44
#define JH7110_GPU_CORE                        45
#define JH7110_GPU_CORE_CLK                    46
#define JH7110_GPU_SYS_CLK                     47
#define JH7110_GPU_CLK_APB                     48
#define JH7110_GPU_RTC_TOGGLE                  49
#define JH7110_NOC_BUS_CLK_GPU_AXI             50
#define JH7110_ISP_TOP_CLK_ISPCORE_2X          51
#define JH7110_ISP_TOP_CLK_ISP_AXI             52
#define JH7110_NOC_BUS_CLK_ISP_AXI             53
#define JH7110_HIFI4_CORE                      54
#define JH7110_HIFI4_AXI                       55
#define JH7110_AXI_CFG1_DEC_CLK_MAIN           56
#define JH7110_AXI_CFG1_DEC_CLK_AHB            57
#define JH7110_VOUT_SRC                        58
#define JH7110_VOUT_AXI                        59
#define JH7110_NOC_BUS_CLK_DISP_AXI            60
#define JH7110_VOUT_TOP_CLK_VOUT_AHB           61
#define JH7110_VOUT_TOP_CLK_VOUT_AXI           62
#define JH7110_VOUT_TOP_CLK_HDMITX0_MCLK       63
#define JH7110_VOUT_TOP_CLK_MIPIPHY_REF        64
#define JH7110_JPEGC_AXI                       65
#define JH7110_CODAJ12_CLK_AXI                 66
#define JH7110_CODAJ12_CLK_CORE                67
#define JH7110_CODAJ12_CLK_APB                 68
#define JH7110_VDEC_AXI                        69
#define JH7110_WAVE511_CLK_AXI                 70
#define JH7110_WAVE511_CLK_BPU                 71
#define JH7110_WAVE511_CLK_VCE                 72
#define JH7110_WAVE511_CLK_APB                 73
#define JH7110_VDEC_JPG_ARB_JPGCLK             74
#define JH7110_VDEC_JPG_ARB_MAINCLK            75
#define JH7110_NOC_BUS_CLK_VDEC_AXI            76
#define JH7110_VENC_AXI                        77
#define JH7110_WAVE420L_CLK_AXI                78
#define JH7110_WAVE420L_CLK_BPU                79
#define JH7110_WAVE420L_CLK_VCE                80
#define JH7110_WAVE420L_CLK_APB                81
#define JH7110_NOC_BUS_CLK_VENC_AXI            82
#define JH7110_AXI_CFG0_DEC_CLK_MAIN_DIV       83
#define JH7110_AXI_CFG0_DEC_CLK_MAIN           84
#define JH7110_AXI_CFG0_DEC_CLK_HIFI4          85
#define JH7110_AXIMEM2_128B_CLK_AXI            86
#define JH7110_QSPI_CLK_AHB                    87
#define JH7110_QSPI_CLK_APB                    88
#define JH7110_QSPI_REF_SRC                    89
#define JH7110_QSPI_CLK_REF                    90
#define JH7110_SDIO0_CLK_AHB                   91
#define JH7110_SDIO1_CLK_AHB                   92
#define JH7110_SDIO0_CLK_SDCARD                93
#define JH7110_SDIO1_CLK_SDCARD                94
#define JH7110_USB_125M                        95
#define JH7110_NOC_BUS_CLK_STG_AXI             96
#define JH7110_GMAC5_CLK_AHB                   97
#define JH7110_GMAC5_CLK_AXI                   98
#define JH7110_GMAC_SRC                        99
#define JH7110_GMAC1_GTXCLK                    100
#define JH7110_GMAC1_RMII_RTX                  101
#define JH7110_GMAC5_CLK_PTP                   102
#define JH7110_GMAC5_CLK_RX                    103
#define JH7110_GMAC5_CLK_RX_INV                104
#define JH7110_GMAC5_CLK_TX                    105
#define JH7110_GMAC5_CLK_TX_INV                106
#define JH7110_GMAC1_GTXC                      107
#define JH7110_GMAC0_GTXCLK                    108
#define JH7110_GMAC0_PTP                       109
#define JH7110_GMAC_PHY                        110
#define JH7110_GMAC0_GTXC                      111
#define JH7110_SYS_IOMUX_PCLK                  112
#define JH7110_MAILBOX_CLK_APB                 113
#define JH7110_INT_CTRL_CLK_APB                114
#define JH7110_CAN0_CTRL_CLK_APB               115
#define JH7110_CAN0_CTRL_CLK_TIMER             116
#define JH7110_CAN0_CTRL_CLK_CAN               117
#define JH7110_CAN1_CTRL_CLK_APB               118
#define JH7110_CAN1_CTRL_CLK_TIMER             119
#define JH7110_CAN1_CTRL_CLK_CAN               120
#define JH7110_PWM_CLK_APB                     121
#define JH7110_DSKIT_WDT_CLK_APB               122
#define JH7110_DSKIT_WDT_CLK_WDT               123
#define JH7110_TIMER_CLK_APB                   124
#define JH7110_TIMER_CLK_TIMER0                125
#define JH7110_TIMER_CLK_TIMER1                126
#define JH7110_TIMER_CLK_TIMER2                127
#define JH7110_TIMER_CLK_TIMER3                128
#define JH7110_TEMP_SENSOR_CLK_APB             129
#define JH7110_TEMP_SENSOR_CLK_TEMP            130
#define JH7110_SPI0_CLK_APB                    131
#define JH7110_SPI1_CLK_APB                    132
#define JH7110_SPI2_CLK_APB                    133
#define JH7110_SPI3_CLK_APB                    134
#define JH7110_SPI4_CLK_APB                    135
#define JH7110_SPI5_CLK_APB                    136
#define JH7110_SPI6_CLK_APB                    137
#define JH7110_I2C0_CLK_APB                    138
#define JH7110_I2C1_CLK_APB                    139
#define JH7110_I2C2_CLK_APB                    140
#define JH7110_I2C3_CLK_APB                    141
#define JH7110_I2C4_CLK_APB                    142
#define JH7110_I2C5_CLK_APB                    143
#define JH7110_I2C6_CLK_APB                    144
#define JH7110_UART0_CLK_APB                   145
#define JH7110_UART0_CLK_CORE                  146
#define JH7110_UART1_CLK_APB                   147
#define JH7110_UART1_CLK_CORE                  148
#define JH7110_UART2_CLK_APB                   149
#define JH7110_UART2_CLK_CORE                  150
#define JH7110_UART3_CLK_APB                   151
#define JH7110_UART3_CLK_CORE                  152
#define JH7110_UART4_CLK_APB                   153
#define JH7110_UART4_CLK_CORE                  154
#define JH7110_UART5_CLK_APB                   155
#define JH7110_UART5_CLK_CORE                  156
#define JH7110_PWMDAC_CLK_APB                  157
#define JH7110_PWMDAC_CLK_CORE                 158
#define JH7110_SPDIF_CLK_APB                   159
#define JH7110_SPDIF_CLK_CORE                  160
#define JH7110_I2STX0_4CHCLK_APB               161
#define JH7110_I2STX_4CH0_BCLK_MST             162
#define JH7110_I2STX_4CH0_BCLK_MST_INV         163
#define JH7110_I2STX_4CH0_LRCK_MST             164
#define JH7110_I2STX0_4CHBCLK                  165
#define JH7110_I2STX0_4CHBCLK_N                166
#define JH7110_I2STX0_4CHLRCK                  167
#define JH7110_I2STX1_4CHCLK_APB               168
#define JH7110_I2STX_4CH1_BCLK_MST             169
#define JH7110_I2STX_4CH1_BCLK_MST_INV         170
#define JH7110_I2STX_4CH1_LRCK_MST             171
#define JH7110_I2STX1_4CHBCLK                  172
#define JH7110_I2STX1_4CHBCLK_N                173
#define JH7110_I2STX1_4CHLRCK                  174
#define JH7110_I2SRX0_3CH_CLK_APB              175
#define JH7110_I2SRX_3CH_BCLK_MST              176
#define JH7110_I2SRX_3CH_BCLK_MST_INV          177
#define JH7110_I2SRX_3CH_LRCK_MST              178
#define JH7110_I2SRX0_3CH_BCLK                 179
#define JH7110_I2SRX0_3CH_BCLK_N               180
#define JH7110_I2SRX0_3CH_LRCK                 181
#define JH7110_PDM_CLK_DMIC                    182
#define JH7110_PDM_CLK_APB                     183
#define JH7110_TDM_CLK_AHB                     184
#define JH7110_TDM_CLK_APB                     185
#define JH7110_TDM_INTERNAL                    186
#define JH7110_TDM_CLK_TDM                     187
#define JH7110_TDM_CLK_TDM_N                   188
#define JH7110_JTAG_CERTIFICATION_TRNG_CLK     189

#define JH7110_SYSCRG_RESET_ASSERT0            190
#define JH7110_SYSCRG_RESET_ASSERT1            191
#define JH7110_SYSCRG_RESET_ASSERT2            192
#define JH7110_SYSCRG_RESET_ASSERT3            193
#define JH7110_SYSCRG_RESET_STATUS0            194
#define JH7110_SYSCRG_RESET_STATUS1            195
#define JH7110_SYSCRG_RESET_STATUS2            196
#define JH7110_SYSCRG_RESET_STATUS3            197

/* aon regisger */
#define JH7110_OSC_DIV4                         0
#define JH7110_AON_APB_FUNC                     1
#define JH7110_U0_GMAC5_CLK_AHB                 2
#define JH7110_U0_GMAC5_CLK_AXI                 3
#define JH7110_GMAC0_RMII_RTX                   4
#define JH7110_U0_GMAC5_CLK_TX                  5
#define JH7110_U0_GMAC5_CLK_TX_INV              6
#define JH7110_U0_GMAC5_CLK_RX                  7
#define JH7110_U0_GMAC5_CLK_RX_INV              8
#define JH7110_OTPC_CLK_APB                     9
#define JH7110_RTC_HMS_CLK_APB                  10
#define JH7110_RTC_INTERNAL                     11
#define JH7110_RTC_HMS_CLK_OSC32K               12
#define JH7110_RTC_HMS_CLK_CAL                  13
#define JH7110_AON_RESET_ASSERT                 14
#define JH7110_AON_RESET_STATUS                 15

/* pmu register */
#define JH71XX_PMU_SW_TURN_ON_POWER             0x0C
#define JH71XX_PMU_SW_TURN_OFF_POWER            0x10
#define JH71XX_PMU_SW_ENCOURAGE                 0x44
#define JH71XX_PMU_TIMER_INT_MASK               0x48
#define JH71XX_PMU_CURR_POWER_MODE              0x80
#define JH71XX_PMU_EVENT_STATUS                 0x88
#define JH71XX_PMU_INT_STATUS                   0x8C

/* otp register */
#define JH7110_OTP_CFG                          0
#define JH7110_OTP_IE                           1
#define JH7110_OTP_SR                           2
#define JH7110_OTP_OPR                          3

#define GPI(x) (x + 2)

#define JH7110_IOMUX_VAL_EN___  0
#define JH7110_IOMUX_VAL_EN_L   0       // LOW
#define JH7110_IOMUX_VAL_EN_H   1       // HIGH
#define JH7110_IOMUX_VAL_EN_2   2       // U0_DOM_VOUT_TOP_U0_HDMI_TX_PIN_CEC_SDA_OEN
#define JH7110_IOMUX_VAL_EN_5   5       // U0_DW_I2C_IC_CLK_OE
#define JH7110_IOMUX_VAL_EN_6   6       // U0_DW_I2C_IC_DATA_OE
#define JH7110_IOMUX_VAL_EN_7   7       // U0_HIFI4_JTDOEN
#define JH7110_IOMUX_VAL_EN_8   8       // U0_JTAG_CERTIFICATION_TDO_OE
#define JH7110_IOMUX_VAL_EN_13  13      // U0_SSP_SPI_NSSPCTLOE
#define JH7110_IOMUX_VAL_EN_14  14      // U0_SSP_SPI_NSSPOE
#define JH7110_IOMUX_VAL_EN_19  19      // U1_DW_SDIO_CCMD_OUT_EN
#define JH7110_IOMUX_VAL_EN_20  20      // U1_DW_SDIO_CDATA_OUT_EN_0
#define JH7110_IOMUX_VAL_EN_21  21      // U1_DW_SDIO_CDATA_OUT_EN_1
#define JH7110_IOMUX_VAL_EN_22  22      // U1_DW_SDIO_CDATA_OUT_EN_2
#define JH7110_IOMUX_VAL_EN_23  23      // U1_DW_SDIO_CDATA_OUT_EN_3
#define JH7110_IOMUX_VAL_EN_28  28      // U1_SSP_SPI_NSSPCTLOE
#define JH7110_IOMUX_VAL_EN_29  29      // U1_SSP_SPI_NSSPOE
#define JH7110_IOMUX_VAL_EN_30  30      // U2_DW_I2C_IC_CLK_OE
#define JH7110_IOMUX_VAL_EN_31  31      // U2_DW_I2C_IC_DATA_OE
#define JH7110_IOMUX_VAL_EN_34  34      // U3_DW_I2C_IC_CLK_OE
#define JH7110_IOMUX_VAL_EN_35  35      // U3_DW_I2C_IC_DATA_OE
#define JH7110_IOMUX_VAL_EN_36  36      // U3_SSP_SPI_NSSPCTLOE
#define JH7110_IOMUX_VAL_EN_37  37      // U3_SSP_SPI_NSSPOE
#define JH7110_IOMUX_VAL_EN_40  40      // U4_SSP_SPI_NSSPCTLOE
#define JH7110_IOMUX_VAL_EN_41  41      // U4_SSP_SPI_NSSPOE
#define JH7110_IOMUX_VAL_EN_42  42      // U5_DW_I2C_IC_CLK_OE
#define JH7110_IOMUX_VAL_EN_43  43      // U5_DW_I2C_IC_DATA_OE

#define JH7110_IOMUX_VAL_OUT___ 0       // LOW
#define JH7110_IOMUX_VAL_OUT_0  0       // LOW
#define JH7110_IOMUX_VAL_OUT_7  7       // U0_CDN_USB_DRIVE_VBUS_IO
#define JH7110_IOMUX_VAL_OUT_10 10      // U0_DOM_VOUT_TOP_U0_HDMI_TX_PIN_CEC_SDA_OUT
#define JH7110_IOMUX_VAL_OUT_13 13      // U0_DSKIT_WDT_WDOGRES
#define JH7110_IOMUX_VAL_OUT_14 14      // U0_DW_I2C_IC_CLK_OUT_A
#define JH7110_IOMUX_VAL_OUT_15 15      // U0_DW_I2C_IC_DATA_OUT_A
#define JH7110_IOMUX_VAL_OUT_19 19      // U0_DW_SDIO_RST_N
#define JH7110_IOMUX_VAL_OUT_20 20      // U0_DW_UART_SOUT
#define JH7110_IOMUX_VAL_OUT_21 21      // U0_HIFI4_JTDO
#define JH7110_IOMUX_VAL_OUT_22 22      // U0_JTAG_CERTIFICATION_TDO
#define JH7110_IOMUX_VAL_OUT_30 30      // U0_SSP_SPI_SSPCLKOUT
#define JH7110_IOMUX_VAL_OUT_31 31      // U0_SSP_SPI_SSPFSSOUT
#define JH7110_IOMUX_VAL_OUT_32 32      // U0_SSP_SPI_SSPTXD
#define JH7110_IOMUX_VAL_OUT_55 55      // U1_DW_SDIO_CCLK_OUT
#define JH7110_IOMUX_VAL_OUT_57 57      // U1_DW_SDIO_CCMD_OUT
#define JH7110_IOMUX_VAL_OUT_58 58      // U1_DW_SDIO_CDATA_OUT_0
#define JH7110_IOMUX_VAL_OUT_59 59      // U1_DW_SDIO_CDATA_OUT_1
#define JH7110_IOMUX_VAL_OUT_60 60      // U1_DW_SDIO_CDATA_OUT_2
#define JH7110_IOMUX_VAL_OUT_61 61      // U1_DW_SDIO_CDATA_OUT_3
#define JH7110_IOMUX_VAL_OUT_73 73      // U1_SSP_SPI_SSPCLKOUT
#define JH7110_IOMUX_VAL_OUT_74 74      // U1_SSP_SPI_SSPFSSOUT
#define JH7110_IOMUX_VAL_OUT_75 75      // U1_SSP_SPI_SSPTXD
#define JH7110_IOMUX_VAL_OUT_78 78      // U2_DW_UART_RTS_N
#define JH7110_IOMUX_VAL_OUT_79 79      // U2_DW_UART_SOUT
#define JH7110_IOMUX_VAL_OUT_83 83      // U3_DW_I2C_IC_CLK_OUT_A
#define JH7110_IOMUX_VAL_OUT_84 84      // U3_DW_I2C_IC_DATA_OUT_A
#define JH7110_IOMUX_VAL_OUT_85 85      // U3_DW_UART_SOUT
#define JH7110_IOMUX_VAL_OUT_86 86      // U3_SSP_SPI_SSPCLKOUT
#define JH7110_IOMUX_VAL_OUT_87 87      // U3_SSP_SPI_SSPFSSOUT
#define JH7110_IOMUX_VAL_OUT_88 88      // U3_SSP_SPI_SSPTXD
#define JH7110_IOMUX_VAL_OUT_93 93      // U4_SSP_SPI_SSPCLKOUT
#define JH7110_IOMUX_VAL_OUT_94 94      // U4_SSP_SPI_SSPFSSOUT
#define JH7110_IOMUX_VAL_OUT_95 95      // U4_SSP_SPI_SSPTXD
#define JH7110_IOMUX_VAL_OUT_91 91      // U4_DW_UART_RTS_N
#define JH7110_IOMUX_VAL_OUT_92 92      // U4_DW_UART_SOUT

#define JH7110_IOMUX_VAL_IN___  0
#define JH7110_IOMUX_VAL_IN_XX  0
#define JH7110_IOMUX_VAL_IN_0   GPI(0)
#define JH7110_IOMUX_VAL_IN_1   GPI(1)
#define JH7110_IOMUX_VAL_IN_2   GPI(2)
#define JH7110_IOMUX_VAL_IN_3   GPI(3)
#define JH7110_IOMUX_VAL_IN_4   GPI(4)
#define JH7110_IOMUX_VAL_IN_6   GPI(6)
#define JH7110_IOMUX_VAL_IN_7   GPI(7)
#define JH7110_IOMUX_VAL_IN_8   GPI(8)
#define JH7110_IOMUX_VAL_IN_9   GPI(9)
#define JH7110_IOMUX_VAL_IN_10  GPI(10)
#define JH7110_IOMUX_VAL_IN_11  GPI(11)
#define JH7110_IOMUX_VAL_IN_12  GPI(12)
#define JH7110_IOMUX_VAL_IN_13  GPI(13)
#define JH7110_IOMUX_VAL_IN_14  GPI(14)
#define JH7110_IOMUX_VAL_IN_15  GPI(15)
#define JH7110_IOMUX_VAL_IN_19  GPI(19) // GPIO19 -> U5_DW_I2C_IC_CLK_IN_A
#define JH7110_IOMUX_VAL_IN_20  GPI(20) // GPIO20 -> U5_DW_I2C_IC_DATA_IN_A
#define JH7110_IOMUX_VAL_IN_36  GPI(36) // GPIO36 -> U0_CLKRST_SRC_BYPASS_JTAG_TRSTN
#define JH7110_IOMUX_VAL_IN_37  GPI(37)
#define JH7110_IOMUX_VAL_IN_38  GPI(38)
#define JH7110_IOMUX_VAL_IN_39  GPI(39)
#define JH7110_IOMUX_VAL_IN_40  GPI(40)
#define JH7110_IOMUX_VAL_IN_43  GPI(43)
#define JH7110_IOMUX_VAL_IN_44  GPI(44)
#define JH7110_IOMUX_VAL_IN_47  GPI(47)
#define JH7110_IOMUX_VAL_IN_48  GPI(48)
#define JH7110_IOMUX_VAL_IN_49  GPI(49)
#define JH7110_IOMUX_VAL_IN_50  GPI(50)
#define JH7110_IOMUX_VAL_IN_52  GPI(52)
#define JH7110_IOMUX_VAL_IN_53  GPI(53)
#define JH7110_IOMUX_VAL_IN_54  GPI(54)
#define JH7110_IOMUX_VAL_IN_56  GPI(56)
#define JH7110_IOMUX_VAL_IN_57  GPI(57)
#define JH7110_IOMUX_VAL_IN_58  GPI(58)
#define JH7110_IOMUX_VAL_IN_60  GPI(60) // GPIO60 -> U0_SYS_CRG_CLK_JTAG_TCK
#define JH7110_IOMUX_VAL_IN_61  GPI(61) // GPIO61 -> U0_JTAG_CERTIFICATION_TDI
#define JH7110_IOMUX_VAL_IN_62  GPI(62)
#define JH7110_IOMUX_VAL_IN_63  GPI(63) // GPIO63 -> U0_JTAG_CERTIFICATION_TMS

#define JH7110_IOMUX_DEN_GROUP(_0, _1, _2, _3)( \
        (JH7110_IOMUX_VAL_EN_##_3 << 24) |                      \
        (JH7110_IOMUX_VAL_EN_##_2 << 16) |                      \
        (JH7110_IOMUX_VAL_EN_##_1 << 8)  |                      \
        JH7110_IOMUX_VAL_EN_##_0)

#define JH7110_IOMUX_DOUT_GROUP(_0, _1, _2, _3)(\
        (JH7110_IOMUX_VAL_OUT_##_3 << 24) |                     \
        (JH7110_IOMUX_VAL_OUT_##_2 << 16) |                     \
        (JH7110_IOMUX_VAL_OUT_##_1 << 8)  |                     \
        (JH7110_IOMUX_VAL_OUT_##_0))

#define JH7110_IOMUX_DIN_GROUP(_0, _1, _2, _3)( \
        (JH7110_IOMUX_VAL_IN_##_3 << 24) |                      \
        (JH7110_IOMUX_VAL_IN_##_2 << 16) |                      \
        (JH7110_IOMUX_VAL_IN_##_1 << 8)  |                      \
        (JH7110_IOMUX_VAL_IN_##_0))

static const char* const jh7110_aon_crg_reg_names[] = {
        "OSC_DIV4",
        "AON_APB_FUNC",
        "U0_GMAC5_CLK_AHB",
        "U0_GMAC5_CLK_AXI",
        "GMAC0_RMII_RTX",
        "U0_GMAC5_CLK_TX",
        "U0_GMAC5_CLK_TX_INV",
        "U0_GMAC5_CLK_RX",
        "U0_GMAC5_CLK_RX_INV",
        "OTPC_CLK_APB",
        "RTC_HMS_CLK_APB",
        "RTC_INTERNAL",
        "RTC_HMS_CLK_OSC32K",
        "RTC_HMS_CLK_CAL",
        "AON_RESET_ASSERT",
        "AON_RESET_STATUS",
};

static_assert(sizeof(jh7110_aon_crg_reg_names) / sizeof(jh7110_aon_crg_reg_names[0]) == JH7110_AON_RESET_ASSERT + 2,
              "check sizeof jh7110_aon_crg_reg_names");


static const char *const jh7110_sys_crg_reg_names[] =
  {
      "CPU_ROOT", // 0
      "CPU_CORE", // 1
      "CPU_BUS", // 2
      "GPU_ROOT", // 3
      "PERH_ROOT", // 4
      "BUS_ROOT", // 5
      "NOCSTG_BUS", // 6
      "AXI_CFG0", // 7
      "STG_AXIAHB", // 8
      "AHB0", // 9
      "AHB1", // 10
      "APB_BUS_FUNC", // 11
      "APB0", // 12
      "PLL0_DIV2", // 13
      "PLL1_DIV2", // 14
      "PLL2_DIV2", // 15
      "AUDIO_ROOT", // 16
      "MCLK_INNER", // 17
      "MCLK", // 18
      "MCLK_OUT", // 19
      "ISP_2X", // 20
      "ISP_AXI", // 21
      "GCLK0", // 22
      "GCLK1", // 23
      "GCLK2", // 24
      "U7_CORE_CLK", //25
      "U7_CORE_CLK1", //26
      "U7_CORE_CLK2", //27
      "U7_CORE_CLK3", //28
      "U7_CORE_CLK4", //29
      "U7_DEBUG_CLK", //30
      "U7_RTC_TOGGLE", //31
      "U7_TRACE_CLK0", //32
      "U7_TRACE_CLK1", //33
      "U7_TRACE_CLK2", //34
      "U7_TRACE_CLK3", //35
      "U7_TRACE_CLK4", //36
      "U7_TRACE_COM_CLK", //37
      "NOC_BUS_CLK_CPU_AXI", //38
      "NOC_BUS_CLK_AXICFG0_AXI", //39
      "OSC_DIV2", //40
      "PLL1_DIV4", //41
      "PLL1_DIV8", //42
      "DDR_BUS", //43
      "DDR_CLK_AXI", //44
      "GPU_CORE", //45
      "GPU_CORE_CLK", //46
      "GPU_SYS_CLK", //47
      "GPU_CLK_APB", //48
      "GPU_RTC_TOGGLE", //49
      "NOC_BUS_CLK_GPU_AXI", //50
      "ISP_TOP_CLK_ISPCORE_2X", //51
      "ISP_TOP_CLK_ISP_AXI", //52
      "NOC_BUS_CLK_ISP_AXI", //53
      "HIFI4_CORE", //54
      "HIFI4_AXI", //55
      "AXI_CFG1_DEC_CLK_MAIN", //56
      "AXI_CFG1_DEC_CLK_AHB", //57
      "VOUT_SRC", //58
      "VOUT_AXI", //59
      "NOC_BUS_CLK_DISP_AXI", //60
      "VOUT_TOP_CLK_VOUT_AHB", //61
      "VOUT_TOP_CLK_VOUT_AXI", //62
      "VOUT_TOP_CLK_HDMITX0_MCLK", //63
      "VOUT_TOP_CLK_MIPIPHY_REF", //64
      "JPEGC_AXI", //65
      "CODAJ12_CLK_AXI", //66
      "CODAJ12_CLK_CORE", //67
      "CODAJ12_CLK_APB", //68
      "VDEC_AXI", //69
      "WAVE511_CLK_AXI", //70
      "WAVE511_CLK_BPU", //71
      "WAVE511_CLK_VCE", //72
      "WAVE511_CLK_APB", //73
      "VDEC_JPG_ARB_JPGCLK", //74
      "VDEC_JPG_ARB_MAINCLK", //75
      "NOC_BUS_CLK_VDEC_AXI", //76
      "VENC_AXI", //77
      "WAVE420L_CLK_AXI", //78
      "WAVE420L_CLK_BPU", //79
      "WAVE420L_CLK_VCE", //80
      "WAVE420L_CLK_APB", //81
      "NOC_BUS_CLK_VENC_AXI", //82
      "AXI_CFG0_DEC_CLK_MAIN_DIV", //83
      "AXI_CFG0_DEC_CLK_MAIN", //84
      "AXI_CFG0_DEC_CLK_HIFI4", //85
      "AXIMEM2_128B_CLK_AXI", //86
      "QSPI_CLK_AHB", //87
      "QSPI_CLK_APB", //88
      "QSPI_REF_SRC", //89
      "QSPI_CLK_REF", //90
      "SDIO0_CLK_AHB", //91
      "SDIO1_CLK_AHB", //92
      "SDIO0_CLK_SDCARD", //93
      "SDIO1_CLK_SDCARD", //94
      "USB_125M", //95
      "NOC_BUS_CLK_STG_AXI", //96
      "GMAC5_CLK_AHB", //97
      "GMAC5_CLK_AXI", //98
      "GMAC_SRC", //99
      "GMAC1_GTXCLK", //100
      "GMAC1_RMII_RTX", //101
      "GMAC5_CLK_PTP", //102
      "GMAC5_CLK_RX", //103
      "GMAC5_CLK_RX_INV", //104
      "GMAC5_CLK_TX", //105
      "GMAC5_CLK_TX_INV", //106
      "GMAC1_GTXC", //107
      "GMAC0_GTXCLK", //108
      "GMAC0_PTP", //109
      "GMAC_PHY", //110
      "GMAC0_GTXC", //111
      "SYS_IOMUX_PCLK", //112
      "MAILBOX_CLK_APB", //113
      "INT_CTRL_CLK_APB", //114
      "CAN0_CTRL_CLK_APB", //115
      "CAN0_CTRL_CLK_TIMER", //116
      "CAN0_CTRL_CLK_CAN", //117
      "CAN1_CTRL_CLK_APB", //118
      "CAN1_CTRL_CLK_TIMER", //119
      "CAN1_CTRL_CLK_CAN", //120
      "PWM_CLK_APB", //121
      "DSKIT_WDT_CLK_APB", //122
      "DSKIT_WDT_CLK_WDT", //123
      "TIMER_CLK_APB", //124
      "TIMER_CLK_TIMER0", //125
      "TIMER_CLK_TIMER1", //126
      "TIMER_CLK_TIMER2", //127
      "TIMER_CLK_TIMER3", //128
      "TEMP_SENSOR_CLK_APB", //129
      "TEMP_SENSOR_CLK_TEMP", //130
      "SPI0_CLK_APB", //131
      "SPI1_CLK_APB", //132
      "SPI2_CLK_APB", //133
      "SPI3_CLK_APB", //134
      "SPI4_CLK_APB", //135
      "SPI5_CLK_APB", //136
      "SPI6_CLK_APB", //137
      "I2C0_CLK_APB", //138
      "I2C1_CLK_APB", //139
      "I2C2_CLK_APB", //140
      "I2C3_CLK_APB", //141
      "I2C4_CLK_APB", //142
      "I2C5_CLK_APB", //143
      "I2C6_CLK_APB", //144
      "UART0_CLK_APB", //145
      "UART0_CLK_CORE", //146
      "UART1_CLK_APB", //147
      "UART1_CLK_CORE", //148
      "UART2_CLK_APB", //149
      "UART2_CLK_CORE", //150
      "UART3_CLK_APB", //151
      "UART3_CLK_CORE", //152
      "UART4_CLK_APB", //153
      "UART4_CLK_CORE", //154
      "UART5_CLK_APB", //155
      "UART5_CLK_CORE", //156
      "PWMDAC_CLK_APB", //157
      "PWMDAC_CLK_CORE", //158
      "SPDIF_CLK_APB", //159
      "SPDIF_CLK_CORE", //160
      "I2STX0_4CHCLK_APB", //161
      "I2STX_4CH0_BCLK_MST", //162
      "I2STX_4CH0_BCLK_MST_INV", //163
      "I2STX_4CH0_LRCK_MST", //164
      "I2STX0_4CHBCLK", //165
      "I2STX0_4CHBCLK_N", //166
      "I2STX0_4CHLRCK", //167
      "I2STX1_4CHCLK_APB", //168
      "I2STX_4CH1_BCLK_MST", //169
      "I2STX_4CH1_BCLK_MST_INV", //170
      "I2STX_4CH1_LRCK_MST", //171
      "I2STX1_4CHBCLK", //172
      "I2STX1_4CHBCLK_N", //173
      "I2STX1_4CHLRCK", //174
      "I2SRX0_3CH_CLK_APB", //175
      "I2SRX_3CH_BCLK_MST", //176
      "I2SRX_3CH_BCLK_MST_INV", //177
      "I2SRX_3CH_LRCK_MST", //178
      "I2SRX0_3CH_BCLK", //179
      "I2SRX0_3CH_BCLK_N", //180
      "I2SRX0_3CH_LRCK", //181
      "PDM_CLK_DMIC", //182
      "PDM_CLK_APB", //183
      "TDM_CLK_AHB", //184
      "TDM_CLK_APB", //185
      "TDM_INTERNAL", //186
      "TDM_CLK_TDM", //187
      "TDM_CLK_TDM_N", //188
      "JTAG_CERTIFICATION_TRNG_CLK", //189
      "SYSCRG_RESET_ASSERT0", //190
      "SYSCRG_RESET_ASSERT1", //191
      "SYSCRG_RESET_ASSERT2", //192
      "SYSCRG_RESET_ASSERT3", //193
      "SYSCRG_RESET_STATUS0", //194
      "SYSCRG_RESET_STATUS1", //195
      "SYSCRG_RESET_STATUS2", //196
      "SYSCRG_RESET_STATUS3", //197
    };

static_assert(sizeof(jh7110_sys_crg_reg_names) / sizeof(jh7110_sys_crg_reg_names[0]) == JH7110_SYSCRG_RESET_ASSERT0 + 4 * 2,
              "check sizeof jh7110_sys_crg_reg_names");


static const char *const jh7110_sys_crg_reset_names[] =
  {
      /*
       * group[0]: syscrg: assert0
       */
      "U0_JTAG2APB_PRESETN", "U0_SYS_SYSCON_PRESETN", "U0_SYS_IOMUX_PRESETN",
      "U0_U7MC_RST_BUS", "U0_U7MC_DEBUG", "U0_U7MC_CORE0", "U0_U7MC_CORE1",
      "U0_U7MC_CORE2", "U0_U7MC_CORE3", "U0_U7MC_CORE4", "U0_U7MC_CORE0_ST",
      "U0_U7MC_CORE1_ST", "U0_U7MC_CORE2_ST", "U0_U7MC_CORE3_ST",
      "U0_U7MC_CORE4_ST", "U0_U7MC_TRACE_RST0", "U0_U7MC_TRACE_RST1",
      "U0_U7MC_TRACE_RST2", "U0_U7MC_TRACE_RST3", "U0_U7MC_TRACE_RST4",
      "U0_U7MC_TRACE_COM", "U0_IMG_GPU_APB", "U0_IMG_GPU_DOMA",
      "U0_NOC_BUS_APB_BUS_N", "U0_NOC_BUS_AXICFG0_AXI_N",
      "U0_NOC_BUS_CPU_AXI_N", "U0_NOC_BUS_DISP_AXI_N", "U0_NOC_BUS_GPU_AXI_N",
      "U0_NOC_BUS_ISP_AXI_N", "U0_NOC_BUS_DDRC_N", "U0_NOC_BUS_STG_AXI_N",
      "U0_NOC_BUS_VDEC_AXI_N",
      /*
       * group[1]: syscrg: assert1
       */
      "U0_NOC_BUS_VENC_AXI_N", "U0_AXI_CFG1_DEC_AHB", "U0_AXI_CFG1_DEC_MAIN",
      "U0_AXI_CFG0_DEC_MAIN", "U0_AXI_CFG0_DEC_MAIN_DIV",
      "U0_AXI_CFG0_DEC_HIFI4", "U0_DDR_AXI", "U0_DDR_OSC", "U0_DDR_APB",
      "U0_DOM_ISP_TOP_N", "U0_DOM_ISP_TOP_AXI", "U0_DOM_VOUT_TOP_SRC",
      "U0_CODAJ12_AXI", "U0_CODAJ12_CORE", "U0_CODAJ12_APB", "U0_WAVE511_AXI",
      "U0_WAVE511_BPU", "U0_WAVE511_VCE", "U0_WAVE511_APB",
      "U0_VDEC_JPG_ARB_JPG", "U0_VDEC_JPG_ARB_MAIN", "U0_AXIMEM_128B_AXI",
      "U0_WAVE420L_AXI", "U0_WAVE420L_BPU", "U0_WAVE420L_VCE",
      "U0_WAVE420L_APB", "U1_AXIMEM_128B_AXI", "U2_AXIMEM_128B_AXI",
      "U0_INTMEM_ROM_SRAM_ROM", "U0_CDNS_QSPI_AHB", "U0_CDNS_QSPI_APB",
      "U0_CDNS_QSPI_REF",
      /*
       * group[2]: syscrg: assert2
       */
      "U0_DW_SDIO_AHB", "U1_DW_SDIO_AHB", "U1_DW_GMAC5_AXI64_A_I",
      "U1_DW_GMAC5_AXI64_H_N", "U0_MAILBOX_RRESETN", "U0_SSP_SPI_APB",
      "U1_SSP_SPI_APB", "U2_SSP_SPI_APB", "U3_SSP_SPI_APB", "U4_SSP_SPI_APB",
      "U5_SSP_SPI_APB", "U6_SSP_SPI_APB", "U0_DW_I2C_APB", "U1_DW_I2C_APB",
      "U2_DW_I2C_APB", "U3_DW_I2C_APB", "U4_DW_I2C_APB", "U5_DW_I2C_APB",
      "U6_DW_I2C_APB", "U0_DW_UART_APB", "U0_DW_UART_CORE", "U1_DW_UART_APB",
      "U1_DW_UART_CORE", "U2_DW_UART_APB", "U2_DW_UART_CORE", "U3_DW_UART_APB",
      "U3_DW_UART_CORE", "U4_DW_UART_APB", "U4_DW_UART_CORE", "U5_DW_UART_APB",
      "U5_DW_UART_CORE", "U0_CDNS_SPDIF_APB",
      /*
       * group[3]: syscrg: assert3
       */
      "U0_PWMDAC_APB", "U0_PDM_4MIC_DMIC", "U0_PDM_4MIC_APB",
      "U0_I2SRX_3CH_APB", "U0_I2SRX_3CH_BCLK", "U0_I2STX_4CH_APB",
      "U0_I2STX_4CH_BCLK", "U1_I2STX_4CH_APB", "U1_I2STX_4CH_BCLK",
      "U0_TDM16SLOT_AHB", "U0_TDM16SLOT_TDM", "U0_TDM16SLOT_APB",
      "U0_PWM_8CH_APB", "U0_DSKIT_WDT_APB", "U0_DSKIT_WDT_CORE",
      "U0_CAN_CTRL_APB", "U0_CAN_CTRL_CORE", "U0_CAN_CTRL_TIMER",
      "U1_CAN_CTRL_APB", "U1_CAN_CTRL_CORE", "U1_CAN_CTRL_TIMER",
      "U0_SI5_TIMER_APB", "U0_SI5_TIMER_TIMER0", "U0_SI5_TIMER_TIMER1",
      "U0_SI5_TIMER_TIMER2", "U0_SI5_TIMER_TIMER3", "U0_INT_CTRL_APB",
      "U0_TEMP_SENSOR_APB", "U0_TEMP_SENSOR_TEMP", "U0_JTAG_CERTIFICATION_N", };


static_assert(sizeof(jh7110_sys_crg_reset_names) / sizeof(jh7110_sys_crg_reset_names[0]) == 126,
              "check sizeof jh7110_sys_crg_reset_names");


#endif
