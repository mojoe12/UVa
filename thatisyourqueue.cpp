#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>


using namespace std;

// function declarations

int main() {
	
	// setup input
	
	for (int c = 1; true; c++) {
		int p, nc;
		cin >> p >> nc;
		if (!p && !nc) break;
				
		queue<int> order1;
		queue<int> order2;
		bool pop1 = true;
		
		for (int i = 1; i <= p; i++) {
			order1.push(i);
		}
		
		queue<int> toskip;
		stack<int> tojump;
		
		
		/*
		
		this code is disgusting and im sorry
		the process is, people go from tojump 
		to toskip to BEING skipped
		
		whenever you print something, it goes
		to the next order
		*/
		
		char com;
		bool skipinput = false;
		
		vector<int> output;
		
		for (int i = 0; i < nc; i++) {
			
			if (!skipinput) cin >> com;
			else {
				i--;
				skipinput = false;
			}
			if (com == 'N')
			{
				if (pop1)
				{
					
					if (tojump.size()) {
						output.push_back(tojump.top());
						toskip.push(tojump.top());
						order2.push(tojump.top());
						tojump.pop();
						continue;
					}
					
					while (toskip.size() && order1.front() == toskip.front()) 
					{
						order1.pop();
						toskip.pop();
						if (!order1.size()) {
							skipinput = true;
							pop1 = !pop1;
							continue;
						}
					}
					
					order2.push(order1.front());
					output.push_back(order1.front());
					order1.pop();
					pop1 = order1.size();
				}
				else 
				{
					cout << "here";
					if (tojump.size()) {
						output.push_back(tojump.top());
						toskip.push(tojump.top());
						order1.push(tojump.top());
						tojump.pop();
						continue;
					}
					
					while (toskip.size() && order2.front() == toskip.front()) 
					{
						order2.pop();
						toskip.pop();
						if (!order1.size()) {
							skipinput = true;
							pop1 = !pop1;
							continue;
						} 
					}
					order1.push(order2.front());
					output.push_back(order2.front());
					order2.pop();
					pop1 = !order2.size();
				}
			}
			
			else
			{
				int x;
				cin >> x;
				tojump.push(x);
				
			}
			
		}
		
		cout << "Case " << c << ":\n";
		for (int i = 0; i < output.size(); i++) cout << output[i] << endl;
		
	}

}