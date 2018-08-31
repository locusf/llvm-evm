class Format<bits<256> val> {
  bits<256> Value = val;
}
def i256: ValueType<256,127>;
def i256imm: Operand<i256>;
class EI<dag oops, dag iops, string opc, string asm, list<dag> pattern> : Instruction {
    field bits<256> Inst;
    let Namespace = "SP";
    let Size = 16;
    dag OutOperandList = oops;
    dag InOperandList = iops;
    let AsmString = !strconcat(opc, "${s}${p}",asm);
    let Pattern = pattern;
    let DecoderNamespace = "EVM";
}
