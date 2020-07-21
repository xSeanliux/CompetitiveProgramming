namespace Solution {
    open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Measurement;
	open Microsoft.Quantum.Canon;
    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        using (q=Qubit[2]){
			X(q[0]);
			X(q[1]);
			unitary(q);
			let m = M(q[0]);
			ResetAll(q);
			if(m == Zero){
				return 1;
			} else {
				return 0;
			}
		}
		
    }
}

