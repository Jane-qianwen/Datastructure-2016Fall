#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

struct Huffman_tree_node //all the input character are the leaves of the huffman tree
{
	int min_ascll_index;
	int weight;
	int parent;     //the parent index in the array
	int left_child;   //the left child index in the array 
	int right_child;   //the right child index in the array
	string huffman_code;
};

void compress(void);
//void Quick_sort(Huffman_tree_node a[],int left,int right);

int main(int argc, char const *argv[])
{
	if (argv[1]=="-d")
	{
		cout <<"hello"<<endl;
		//decompress();
	}
	else
	{
		compress();

	}
	return 0;
}

void compress(void)
{
	int char_amout = 0;
	int array[256]={0};//initial an array to store all the frequency of the 0~255 ASCII
	string txt;//to store all the input txt
	while (!cin.eof())//read the input file from beginning to the end
	{
		char current = cin.get();
		array[current]++;//get the frequency of every ascll character
		txt.push_back(current);
		char_amout ++;
	}
	//compressed data part1
	cout << hex <<'H'<<'U'<< 'F'<<'F'<<'M'<<'A'<<'N'<<'\0';
	//compressed data part2
	for (int i=0;i<256;i++)
	{
		int digit =  0;//use this variable to store how much digit of thefrequency
		int frequency_to_print = array[i];
		while (frequency_to_print!=0)
		{
			char tmp= frequency_to_print%256;
			cout << hex <<tmp;
			frequency_to_print = frequency_to_print/256;
			digit ++;//this frequecy has got two more hex digit
		}
		for(int j=digit;j<4;j++)
		{
			cout <<hex<<'\0';
		}
	}
	//priority input ascll characters by their frequency
	int count_leaf = 0;//store how many characters appear in the input
	//get the initial size of the priority queue
	for (int i=0;i<=255;i++)
	{
		if (array[i]>0)//ascll appear in the input txt 
		{
			count_leaf++;
		}
	}
	int node_max  = 2*count_leaf-1;//the , so we can get the actual size of the struct array
	Huffman_tree_node priority_queue[node_max];//state an array of the huffman_tree_node
	//get the information of  all the input character
	for (int m=0,j=0;m<=255;m++)
	{
		if (array[m]>0)
		{
			priority_queue[j].min_ascll_index = m;
			priority_queue[j].weight = array[m];
			priority_queue[j].parent = -1;
			priority_queue[j].left_child = -1;
			priority_queue[j].right_child = -1;
			j++;
		}
	}
	//initial the information of the nodes that are internal leaf nodes
	for (int m=count_leaf;m<node_max;m++)
	{
		priority_queue[m].weight = 0;
		priority_queue[m].parent = -1;
		priority_queue[m].left_child = -1;
		priority_queue[m].right_child = -1;
	}
	//now we start to merge
	int array_size=count_leaf;
	while (array_size < node_max)
	{
		int high_priority;
		int low_priority;
		int start;
		//find the first node whose parent is -1
		for (int j=0;j<array_size;j++)
		{
			if (priority_queue[j].parent==-1)
			{
				start= j;
				high_priority = j;
				low_priority = j;
				break;
			}
		}
		for (int i=start+1;i<array_size;i++)
		{

			if (priority_queue[i].weight<priority_queue[high_priority].weight && priority_queue[i].parent==-1)
			{
				low_priority = high_priority;
				high_priority = i;
			}
			else if (priority_queue[i].weight==priority_queue[high_priority].weight && priority_queue[i].parent==-1)
			{
				if (priority_queue[i].min_ascll_index<priority_queue[high_priority].min_ascll_index)
				{
					low_priority = high_priority;
					high_priority = i;
				}
				else
				{
					if (priority_queue[i].weight<priority_queue[low_priority].weight)
					{
						low_priority = i;
						high_priority = high_priority;
					}
					else if (priority_queue[i].weight==priority_queue[low_priority].weight && priority_queue[i].min_ascll_index<priority_queue[low_priority].min_ascll_index)
					{
						low_priority = i;
						high_priority = high_priority;
					}
					else
					{
						low_priority = low_priority;
						high_priority = high_priority;
					}
				}
			}
			else if(priority_queue[i].weight>priority_queue[high_priority].weight && priority_queue[i].parent==-1)
			{
				if (priority_queue[i].weight<priority_queue[low_priority].weight)
				{
					low_priority=i;
					high_priority = high_priority;
				}
				else if (priority_queue[i].weight==priority_queue[low_priority].weight && priority_queue[i].min_ascll_index<priority_queue[low_priority].min_ascll_index)
				{
					low_priority = i;
					high_priority = high_priority;
				}
				else
				{
					low_priority = low_priority;
					high_priority = high_priority;
				}
			}
			else
			{
				low_priority = low_priority;
				high_priority = high_priority;
			}
		}
		if (low_priority==high_priority)
		{
			//to find the next highest priority  to be the low priority
			for (int i=high_priority+1;i<array_size;i++)
			{
				if(priority_queue[i].parent==-1)
				{
					int min=i;
					int k=i+1;
					while (k<array_size)
					{
						if (priority_queue[k].weight<priority_queue[min].weight&&priority_queue[k].parent==-1)
						{
							min = k;
						}
						if (priority_queue[k].weight==priority_queue[min].weight&&priority_queue[k].parent==-1)
						{
							if (priority_queue[k].min_ascll_index<priority_queue[i].min_ascll_index)
							{
								min = k;
							}
							else
							{
								min = min;
							}
						}
						k++;
					}
					low_priority = min;
					break;
				}
			}
		}			
		priority_queue[array_size].left_child = low_priority;
		priority_queue[array_size].right_child = high_priority;
		priority_queue[array_size].weight = priority_queue[low_priority].weight + priority_queue[high_priority].weight;
		if (priority_queue[high_priority].min_ascll_index<priority_queue[low_priority].min_ascll_index)
		{
			priority_queue[array_size].min_ascll_index = priority_queue[high_priority].min_ascll_index;
		}
		else
		{
			priority_queue[array_size].min_ascll_index = priority_queue[low_priority].min_ascll_index;
		}
		priority_queue[high_priority].parent = array_size;
		priority_queue[low_priority].parent = array_size;
		array_size++;
		//one more node whose weight >0
	}
	//priority_queue[node_max-1] is the whole huffman tree
	//start to get the huffman code of every character
	for (int i=0;i<count_leaf;i++)
	{
		int j = i;
		string a="";
		while (j!=node_max-1)
		{
			int child=j;
			j=priority_queue[j].parent;
			if (priority_queue[j].left_child==child)
			{
				a.push_back('0');
			}
			else
			{
				a.push_back('1');
			}
		}
		//reverse the huffman code to get the right order
		int len = a.length();
 		for (int m = 0; m<len/2; m++)
		{
  			//前后交换
  			char tmp = a[m];
  			a[m] = a[len-m-1];
  			a[len-m-1] = tmp;
 		}
  		priority_queue[i].huffman_code=a;
	}
	//compressed data part3
	string huffman_binary="";//store all the huffman code in the order character appears
	for (int i=0;i<char_amout;i++)
	{
		for (int j=0;j<count_leaf;j++)
		{
			if (int (txt[i])==priority_queue[j].min_ascll_index)
			{
				huffman_binary  += priority_queue[j].huffman_code;
				break;
			}
		}
	}
	while (huffman_binary.size()%8!=0)
	{
		huffman_binary.push_back('0');
	}
	for (int i=0;i<(huffman_binary.size()/8);i++)
	{
		string eight_hufffman_code = huffman_binary.substr(i*8,8);
		int len = eight_hufffman_code.length();
		//reverse the huffmancode
 		for (int m = 0; m<len/2; m++)
		{
  			//前后交换
  			char tmp = eight_hufffman_code[m];
  			eight_hufffman_code[m] = eight_hufffman_code[len-m-1];
  			eight_hufffman_code[len-m-1] = tmp;
 		}
		char piece[8];
		for (int i=0;i<8;i++)
		{
			piece[i]=eight_hufffman_code[i];
		}
 		//convert binary to decimal
 		int dec_code = strtoul(piece,NULL,2);
 		int frequency_to_print = dec_code;
		while (frequency_to_print!=0)
		{
			char tmp= frequency_to_print%256;
			cout << hex <<tmp;
			frequency_to_print = frequency_to_print/256;
		}
	}
}


