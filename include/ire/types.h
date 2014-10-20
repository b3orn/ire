#ifndef IRE_TYPES_H
#define IRE_TYPES_H

typedef size_t ire_error_t;
typedef uint8_t ire_opcode_t;


typedef struct ire_code   ire_code_t;
typedef struct ire_data   ire_data_t;
typedef struct ire_binary ire_binary_t;


typedef struct ire_cpu ire_cpu_t;


typedef struct ire_instruction_nop  ire_instruction_nop_t;
typedef struct ire_instruction_cpy  ire_instruction_cpy_t;
typedef struct ire_instruction_sto  ire_instruction_sto_t;
typedef struct ire_instruction_lod  ire_instruction_lod_t;
typedef struct ire_instruction_psh  ire_instruction_psh_t;
typedef struct ire_instruction_pop  ire_instruction_pop_t;
typedef struct ire_instruction_cal  ire_instruction_cal_t;
typedef struct ire_instruction_jmp  ire_instruction_jmp_t;
typedef struct ire_instruction_irt  ire_instruction_irt_t;
typedef struct ire_instruction_ret  ire_instruction_ret_t;
typedef struct ire_instruction_iret ire_instruction_iret_t;
typedef struct ire_instruction_cmp  ire_instruction_cmp_t;
typedef struct ire_instruction_add  ire_instruction_add_t;
typedef struct ire_instruction_sub  ire_instruction_sub_t;
typedef struct ire_instruction_mul  ire_instruction_mul_t;
typedef struct ire_instruction_div  ire_instruction_div_t;
typedef struct ire_instruction_mod  ire_instruction_mod_t;
typedef struct ire_instruction_neg  ire_instruction_neg_t;
typedef struct ire_instruction_and  ire_instruction_and_t;
typedef struct ire_instruction_or   ire_instruction_or_t;
typedef struct ire_instruction_xor  ire_instruction_xor_t;
typedef struct ire_instruction_not  ire_instruction_not_t;
typedef struct ire_instruction_shl  ire_instruction_shl_t;
typedef struct ire_instruction_shr  ire_instruction_shr_t;
typedef struct ire_instruction_rol  ire_instruction_rol_t;
typedef struct ire_instruction_ror  ire_instruction_ror_t;
typedef struct ire_instruction_in   ire_instruction_in_t;
typedef struct ire_instruction_out  ire_instruction_out_t;
typedef struct ire_instruction_hlt  ire_instruction_hlt_t;
typedef struct ire_instruction_hlti ire_instruction_hlti_t;

typedef struct ire_instruction_cmpi ire_instruction_cmpi_t;
typedef struct ire_instruction_addi ire_instruction_addi_t;
typedef struct ire_instruction_subi ire_instruction_subi_t;
typedef struct ire_instruction_muli ire_instruction_muli_t;
typedef struct ire_instruction_divi ire_instruction_divi_t;
typedef struct ire_instruction_modi ire_instruction_modi_t;
typedef struct ire_instruction_andi ire_instruction_andi_t;
typedef struct ire_instruction_ori  ire_instruction_ori_t;
typedef struct ire_instruction_xori ire_instruction_xori_t;
typedef struct ire_instruction_shli ire_instruction_shli_t;
typedef struct ire_instruction_shri ire_instruction_shri_t;
typedef struct ire_instruction_roli ire_instruction_roli_t;
typedef struct ire_instruction_rori ire_instruction_rori_t;
typedef struct ire_instruction_ini  ire_instruction_ini_t;
typedef struct ire_instruction_outi ire_instruction_outi_t;

typedef struct ire_instruction_lodi ire_instruction_lodi_t;
typedef struct ire_instruction_esc  ire_instruction_esc_t;
typedef struct ire_instruction_cali ire_instruction_cali_t;
typedef struct ire_instruction_irti ire_instruction_irti_t;
typedef struct ire_instruction_jmpi ire_instruction_jmpi_t;

typedef union ire_instruction ire_instruction_t;

typedef ire_error_t (*ire_instruction_handler_t)(
    ire_instruction_t *instruction,
    ire_cpu_t *cpu);


struct ire_code {
    uint16_t base;
    uint16_t entry;
    uint16_t stack_base;
    uint16_t interrupt_base;
    uint16_t interrupt_table[1024];
    uint16_t size;
    uint8_t data[];
};


struct ire_data {
    uint16_t base;
    uint16_t zero;
    uint16_t size;
    uint8_t data[];
};


struct ire_binary {
    uint8_t magic[4];
    uint32_t version;
    ire_data_t *data;
    ire_code_t *code;
};


struct ire_cpu {
    uint16_t interrupt;
    uint16_t interrupt_table;
    uint16_t size;
    uint16_t registers[16];
    uint8_t memory[];
};

struct ire_instruction_nop {
    uint16_t group: 2;
    uint16_t opcode: 6;
    uint16_t padding: 8;
};


struct ire_instruction_cpy {
    uint16_t group: 2;
    uint16_t opcode: 6;
    uint16_t destination: 4;
    uint16_t source: 4;
};


struct ire_instruction_sto {
    uint16_t group: 2;
    uint16_t opcode: 6;
    uint16_t destination: 4;
    uint16_t source: 4;
};


struct ire_instruction_lod {
    uint16_t group: 2;
    uint16_t opcode: 6;
    uint16_t destination: 4;
    uint16_t source: 4;
};


struct ire_instruction_psh {
    uint16_t group: 2;
    uint16_t opcode: 6;
    uint16_t padding: 4;
    uint16_t source: 4;
};


struct ire_instruction_pop {
    uint16_t group: 2;
    uint16_t opcode: 6;
    uint16_t padding: 4;
    uint16_t destination: 4;
};


struct ire_instruction_cal {
    uint16_t group: 2;
};


struct ire_instruction_jmp {
    uint16_t group: 2;
};


struct ire_instruction_irt {
    uint16_t group: 2;
};


struct ire_instruction_ret {
    uint16_t group: 2;
};


struct ire_instruction_iret {
    uint16_t group: 2;
};


struct ire_instruction_cmp {
    uint16_t group: 2;
};


struct ire_instruction_add {
    uint16_t group: 2;
};


struct ire_instruction_sub {
    uint16_t group: 2;
};


struct ire_instruction_mul {
    uint16_t group: 2;
};


struct ire_instruction_div {
    uint16_t group: 2;
};


struct ire_instruction_mod {
    uint16_t group: 2;
};


struct ire_instruction_neg {
    uint16_t group: 2;
};


struct ire_instruction_and {
    uint16_t group: 2;
};


struct ire_instruction_or {
    uint16_t group: 2;
};


struct ire_instruction_xor {
    uint16_t group: 2;
};


struct ire_instruction_not {
    uint16_t group: 2;
};


struct ire_instruction_shl {
    uint16_t group: 2;
};


struct ire_instruction_shr {
    uint16_t group: 2;
};


struct ire_instruction_rol {
    uint16_t group: 2;
};


struct ire_instruction_ror {
    uint16_t group: 2;
};


struct ire_instruction_in {
    uint16_t group: 2;
};


struct ire_instruction_out {
    uint16_t group: 2;
};


struct ire_instruction_hlt {
    uint16_t group: 2;
};


struct ire_instruction_hlti {
    uint16_t group: 2;
};


struct ire_instruction_cmpi {
    uint16_t group: 2;
};


struct ire_instruction_addi {
    uint16_t group: 2;
};


struct ire_instruction_subi {
    uint16_t group: 2;
};


struct ire_instruction_muli {
    uint16_t group: 2;
};


struct ire_instruction_divi {
    uint16_t group: 2;
};


struct ire_instruction_modi {
    uint16_t group: 2;
};


struct ire_instruction_andi {
    uint16_t group: 2;
};


struct ire_instruction_ori {
    uint16_t group: 2;
};


struct ire_instruction_xori {
    uint16_t group: 2;
};


struct ire_instruction_shli {
    uint16_t group: 2;
};


struct ire_instruction_shri {
    uint16_t group: 2;
};


struct ire_instruction_roli {
    uint16_t group: 2;
};


struct ire_instruction_rori {
    uint16_t group: 2;
};


struct ire_instruction_ini {
    uint16_t group: 2;
};


struct ire_instruction_outi {
    uint16_t group: 2;
};


struct ire_instruction_lodi {
    uint16_t group: 2;
};


struct ire_instruction_esc {
    uint16_t group: 2;
};


struct ire_instruction_cali {
    uint16_t group: 2;
};


struct ire_instruction_irti {
    uint16_t group: 2;
};


struct ire_instruction_jmpi {
    uint16_t group: 2;
};


union ire_instruction {
    uint16_t generic;
    ire_instruction_nop_t  nop;
    ire_instruction_cpy_t  cpy;
    ire_instruction_sto_t  sto;
    ire_instruction_lod_t  lod;
    ire_instruction_psh_t  psh;
    ire_instruction_pop_t  pop;
    ire_instruction_cal_t  cal;
    ire_instruction_jmp_t  jmp;
    ire_instruction_irt_t  irt;
    ire_instruction_ret_t  ret;
    ire_instruction_iret_t iret;
    ire_instruction_cmp_t  cmp;
    ire_instruction_add_t  add;
    ire_instruction_sub_t  sub;
    ire_instruction_mul_t  mul;
    ire_instruction_div_t  div;
    ire_instruction_mod_t  mod;
    ire_instruction_neg_t  neg;
    ire_instruction_and_t  and;
    ire_instruction_or_t   or;
    ire_instruction_xor_t  xor;
    ire_instruction_not_t  not;
    ire_instruction_shl_t  shl;
    ire_instruction_shr_t  shr;
    ire_instruction_rol_t  rol;
    ire_instruction_ror_t  ror;
    ire_instruction_in_t   in;
    ire_instruction_out_t  out;
    ire_instruction_hlt_t  hlt;
    ire_instruction_hlti_t hlti;
    ire_instruction_cmpi_t cmpi;
    ire_instruction_addi_t addi;
    ire_instruction_subi_t subi;
    ire_instruction_muli_t muli;
    ire_instruction_divi_t divi;
    ire_instruction_modi_t modi;
    ire_instruction_andi_t andi;
    ire_instruction_ori_t  ori;
    ire_instruction_xori_t xori;
    ire_instruction_shli_t shli;
    ire_instruction_shri_t shri;
    ire_instruction_roli_t roli;
    ire_instruction_rori_t rori;
    ire_instruction_ini_t  ini;
    ire_instruction_outi_t outi;
    ire_instruction_lodi_t lodi;
    ire_instruction_esc_t  esc;
    ire_instruction_cali_t cali;
    ire_instruction_irti_t irti;
    ire_instruction_jmpi_t jmpi;
};

#endif
