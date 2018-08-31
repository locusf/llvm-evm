def NonretBinOp: SDTypeProfile<0,2,[     // add, and, or, xor, udiv, etc.
SDTCisInt<1>
]>;
def ADDIns: SDNode<"EVM::ADD", NonretBinOp, []>;
def ADD: EI<(outs i256imm:$dst), (ins i256imm:$src), "0x01", "ADD",
    [(ADDIns i256:$src,i256:$dst)]>;
