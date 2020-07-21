namespace Solution {
    open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Measurement;
	open Microsoft.Quantum.Canon;
    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        using (q=Qubit[2]){
			X(q[0]);
			X(q[1]);
			unitary(q);
			let m1 = M(q[0]);
			let m2 = M(q[1]);
			mutable ans = 0;
			mutable jizz = 0;
			if(m1 == Zero){
				set ans = 2;
				set jizz = 1;
			}
			if(m2 == Zero){
				set ans = 1;	
				set jizz = 1;
			}
			if(jizz == 0){
				ResetAll(q);
				X(q[0]);
				unitary(q);
				let m3 = M(q[0]);
				if(m3 == One){
					set ans = 0;
				} else {
					set ans = 3;
				}
			}
			ResetAll(q);
			return ans;
		}
		
    }
}


