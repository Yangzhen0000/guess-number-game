//Game_guess_number.cpp
//A game for users to guess the random number and tell the result

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{    int random_num[3], user_guess_num[3];                                   //two arrays to contain the random number and user guess number respectively
	 int play_coun = 0, win = 0, lose = 0, all_right = 0, num_right = 0, time_coun = 0;     //time recorders
     char choice;                                                               //decide play the game or not

     while (true){
	 
	     srand(time(NULL));                                                     //random number seed initialized
     
		 cout << "Do you want to play the game_guess_number（Y/N）?" << endl; 
		 cin >> choice;
         
         time_coun = 0;
		 if (choice == 'N'){
             cout << "You have totally played " << play_coun << " time(s), and you have won " << win << " time(s)，lost " << lose << " time(s)。" << endl;
             break;
         }                                                                                 //put out the result when end the game
		 if (choice == 'Y'){
            play_coun += 1;
		 	random_num[0] = rand() % 10;
		 	do {
		     	random_num[1] = rand() % 10;
		 	} while (random_num[1] == random_num[0]);
		 	do {
		 	 	random_num[2] = rand() % 10;
		 	} while (random_num[2] == random_num[0] || random_num[2] == random_num[1]);    //create three different random numbers
		 	cout << random_num[0] << random_num[1] << random_num[2];
	 	 	
			while (true) {
		     	cout << "Please input three different numbers you guess：" << endl;        
     	     	all_right = 0, num_right = 0, time_coun += 1;
     	     	
     	     	bool flag = true;
				do{
				    cin >> user_guess_num[0] >> user_guess_num[1] >> user_guess_num[2];
     	     	    if (cin.fail()){
				        flag = false;
					    cout << "Your inputs are ilegal, please input again:\n";
				        cin.clear();
				        cin.sync();
				    }
				    else flag = true;
				}while (flag == false);                                                    //check the inputs, avoid dead line
			 	
				num_right = (user_guess_num[0] == random_num[1]) + (user_guess_num[0] == random_num[2]) + (user_guess_num[1] == random_num[0])
				  + (user_guess_num[1] == random_num[2] ) + (user_guess_num[2] == random_num[0]) + (user_guess_num[2] == random_num[1]);                                                                     
				all_right = (user_guess_num[0] == random_num[0]) + (user_guess_num[1] == random_num[1]) + (user_guess_num[2] == random_num[2]);
				                                                                           //get in the user-guess number, compare and register
	         	if (all_right == 3){
	         		win += 1;
	         		cout << "Congratulations! You win!" << endl; 
	         		break;                                                                 //output the result when you are right
			 	}    
	         	else cout << all_right << 'A' << num_right << 'B' << endl;                 //output the tips when you are wrong
	            if (time_coun == 7){
		         	lose += 1;
				 	cout << "It is regretful that you haven't gotten the right numbers in 7 times, the answer is";
	             	for (int i = 0; i < 3 ; ++i)
	                 	cout << random_num[i];  
	             	cout << endl; 
			     	break;                                                                 //play 7 times until you are right
		     	} 
          	}
		}
	}
	return 0;
}
