namespace Solution {
    open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Measurement;
	open Microsoft.Quantum.Canon;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        // your code here
		using(q = Qubit()){
			unitary(q);
			Z(q);
			unitary(q);
			let m = MResetZ(q);
			return m == Zero ? 1 | 0;
		}
    }
}
