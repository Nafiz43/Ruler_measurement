#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int scale_1;
int scale_2;
int final_goal;
int c=0;
class state
{
public:
	
	int color;
	int scale_1_leftx;
	int scale_2_leftx;
	// int left;
	// int right;
	// int middle;
	state()
	{
		color=0;
		scale_1_leftx=0;
		scale_2_leftx=0;
		//print();
		// left=abs(scale_1_leftx - scale_2_leftx );
		// right=abs((scale_1_leftx+scale_1)-( scale_2_leftx + scale_2 ));
		// middle=abs( (scale_1_leftx+scale_1) - (scale_2_leftx) );
	}
	state(int p,int q)
	{
		scale_1_leftx=p;
		scale_2_leftx=q;
		// left=abs(scale_1_leftx - scale_2_leftx );
		// right=abs((scale_1_leftx+scale_1)-( scale_2_leftx + scale_2 ));
		// middle=abs( (scale_1_leftx+scale_1) - (scale_2_leftx) );
	}
	void calc()
	{
		int left=abs(scale_1_leftx - scale_2_leftx );
		int right=abs((scale_1_leftx+scale_1)-( scale_2_leftx + scale_2 ));
		int middle=abs( (scale_1_leftx+scale_1) - (scale_2_leftx) );
		cout<<left<<" "<<middle<<" "<<right<<endl;
	}
	void print()
	{
		cout<<"State Condition: ";
		cout<<scale_1_leftx<<" "<<scale_2_leftx<<endl;
	//	cout<<endl;
	}
	state* gen_next_state()
	{
		state *genarated;
		genarated=new state[4];

		//state genarated[4];
		//genarated=new state[4];
		int initial_scale_1_leftx=scale_1_leftx;
		int initial_scale_2_leftx=scale_2_leftx;

		int p=0;
		int q=0;
		//turn over scale_1 left
		genarated[0].scale_1_leftx=initial_scale_1_leftx -  scale_1;
		genarated[0].scale_2_leftx=initial_scale_2_leftx;
	//	genarated[0].print();

		//turn over scale_1 right
		genarated[1].scale_1_leftx=initial_scale_1_leftx + scale_1;
		genarated[1].scale_2_leftx=initial_scale_2_leftx;
	//	genarated[1].print();

		//turn over scale_2 left
		genarated[2].scale_1_leftx=initial_scale_1_leftx;
		genarated[2].scale_2_leftx=initial_scale_2_leftx - scale_2;
	//	genarated[2].print();

		//turn over scale_2 right
		genarated[3].scale_1_leftx = initial_scale_1_leftx;
		genarated[3].scale_2_leftx = initial_scale_2_leftx + scale_2;
	//	genarated[3].print();


		return genarated;

	}

};
state final_goal_state;
state initial_state;
class mapping
{
	public:
	state parent;
	state child;
		
};
mapping m[100];
class bfs
{
	list<state> li;
	map<state,state> Map;
	
public:
	bfs()
	{

	}
	bool check_goal(state src)
	{
		int left=abs(src.scale_1_leftx - src.scale_2_leftx );
		int right=abs((src.scale_1_leftx+scale_1)-( src.scale_2_leftx + scale_2 ));
		int middle=abs( (src.scale_1_leftx+scale_1) - (src.scale_2_leftx) );
	//	cout<<"state condition : "<<left<<" "<<middle <<" "<<right<<endl;
		if (left==final_goal || middle==final_goal || right==final_goal)
		{
			//cout<<"hell yeah"<<endl;
			/* code */
			return true;
		}
		else
		{
			return false;
		}

	}
	void back_track(state p,state q)
	{
		list<state> pq;
		cout<<"Backtrack"<<endl;
		
	//	cout<<"Printing P and q"<<endl;
		//p.print();
	//	q.print();
		pq.push_back(q);
		
		cout<<endl;
		x:
		for (int i=0;i<c;i++)
		{
			if(m[i].child.scale_1_leftx==p.scale_1_leftx && m[i].child.scale_2_leftx==p.scale_2_leftx)
			{
			//	p.print();
				pq.push_back(p);
				
				//cout<<"Parent found"<<endl;
				p=m[i].parent;
				q=m[i].child;
			//	q.print();
				if(p.scale_1_leftx==initial_state.scale_1_leftx && p.scale_2_leftx== initial_state.scale_2_leftx )
				{
				//	p.print();
					
					pq.push_back(p);
					//cout<<"Source found"<<endl;
					break;
				}
				else
				{
					goto x;			
				}
				
			}
		}
		int k=1;
		pq.reverse();
		while(pq.size())
		{
			cout<<"Step : "<<k<<endl;
			state w=pq.front();
			w.print();
			w.calc();
			cout<<endl;
			
			pq.pop_front();
			k++;
		}
		cout<<"Goal Reached"<<endl;
		
	}
	void run_bfs(state src)
	{
		
		
		
		if(check_goal(src))
		{
			//cout<<"find goal without any looping"<<endl;


		}
		else
		{
		//	cout<<"did not find goal"<<endl;
			int flag=0;
			
			li.push_back(src);
			while(!li.empty())
			{
				state p=li.front();
				li.pop_front();

				flag=0;
				state *q;
				q=p.gen_next_state();
				for (int i = 0; i < 4; ++i)
				{
					if(check_goal(q[i]))
					{
						//cout<<"found goal"<<endl;
						q[i].print();
						flag=1;
						final_goal_state=q[i];
						
						back_track(p,q[i]);
						break;
					}
					else
					{
						if(q[i].color==0)
						{
							li.push_back(q[i]);	
							q[i].color=1;
							
							m[c].child=q[i];
							m[c].parent=p;	
							c++;	
						}
					}
					/* code */
				}
				if(flag==1)
				{
					break;
				}
			
				
			}
		}

		

	}

	
};
int main()
{
	scale_1=7;
	scale_2=5;
	final_goal=1;

	state src;
	initial_state=src;
	bfs bs;
	bs.run_bfs(src);

	// genarated=new state();
	// genarated->gen_next_state();

	// int q;
	// cout<<"Enter length of scale_1"<<endl;
	// cin>>scale_1;
	// cout<<"Enter length of scale_2"<<endl;

	// cin>>scale_2;
	// cout<<"Enter measurement goal"<<endl;

}

