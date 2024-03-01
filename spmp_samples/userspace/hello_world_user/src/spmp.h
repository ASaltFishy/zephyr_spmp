#ifndef SPMP
#define SPMP

#define SMPU_READ_CFG(g) ({                                    \
    unsigned long csr_value;                                      \
    __asm__ volatile("csrr %0, " #g : "=r"(csr_value)); \
    csr_value;                                                    \
})

#define CSR_SMPUCFG0 0x1a0
#define CSR_SMPUCFG1 0x1a1
#define CSR_SMPUCFG2 0x1a2
#define CSR_SMPUCFG3 0x1a3
#define CSR_SMPUCFG4 0x1a4
#define CSR_SMPUCFG5 0x1a5
#define CSR_SMPUCFG6 0x1a6
#define CSR_SMPUCFG7 0x1a7
#define CSR_SMPUCFG8 0x1a8
#define CSR_SMPUCFG9 0x1a9
#define CSR_SMPUCFG10 0x1aa
#define CSR_SMPUCFG11 0x1ab
#define CSR_SMPUCFG12 0x1ac
#define CSR_SMPUCFG13 0x1ad
#define CSR_SMPUCFG14 0x1ae
#define CSR_SMPUCFG15 0x1af
#define CSR_SMPUADDR0 0x1b0
#define CSR_SMPUADDR1 0x1b1
#define CSR_SMPUADDR2 0x1b2
#define CSR_SMPUADDR3 0x1b3
#define CSR_SMPUADDR4 0x1b4
#define CSR_SMPUADDR5 0x1b5
#define CSR_SMPUADDR6 0x1b6
#define CSR_SMPUADDR7 0x1b7
#define CSR_SMPUADDR8 0x1b8
#define CSR_SMPUADDR9 0x1b9
#define CSR_SMPUADDR10 0x1ba
#define CSR_SMPUADDR11 0x1bb
#define CSR_SMPUADDR12 0x1bc
#define CSR_SMPUADDR13 0x1bd
#define CSR_SMPUADDR14 0x1be
#define CSR_SMPUADDR15 0x1bf
#define CSR_SMPUADDR16 0x1c0

#endif