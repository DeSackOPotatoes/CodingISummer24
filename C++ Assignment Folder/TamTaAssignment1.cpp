#include <iostream> // i've recently learning most of C++ through wsu so I won't be adding too many reminder notes
#include <string>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <thread>

using namespace std;

int main() {

    srand(time(NULL)); //Generates a seed based on the time
  
    /* I got to add a narrative element to keep my mind sane while coding. Also, for me it's great to have notifications pop out in the console at each step of the process so I know where things are bugged at. This comes in the form of narrative descriptions */

    cout << "This is the story of a fledgling hero who is bound to establish a great legacy, this is your story.\n\n";
    cout << "\tThe local guild hall in front of you is a relatively small operation for the area. The frontier has always been a more unknown and precarious environment to adventure in. One typically only finds veteran explorers or naive newcomers employing themselves here. You are among the latter.\n\n";
    cout << "\tEntering the building, there is not a single soul in the main hall besides a young lady sitting behind a lone desk. She seems to be engrossed in a book but raises her eye to meet yours as you inspect the hall. As you walk up to her, her lethargic demeanor gives way to a mustered excitement. She greets you.\n\n";
    cout << "\"Hello adventurer! Please register your name with us for your liscense.\"\n\n";
    cout << "What is your name?\n";

    string playerName;
    cin >> playerName;
    cout << endl;

    cout << "\"Welcome to the adventurer's guild " << playerName << ", we are glad to have you here.\"\n\n";
    cout << "Looking down at your registration card as you leave the building, you are filled with determination for your journey ahead. There is also information on your status labeled there. It states that your HP is 10, whatever that means.\n\n";

    this_thread::sleep_for(2000ms);

    int playerHP = 10;
    int enemyATK = 0;
    int playerBLOCK = 0;
    int TURN = 0;
    int rewardGOLD = 0;
    int rewardEXP = 0;
    int playerGOLD = 0;
    int playerEXP = 0;
    char abandonChoice;
    bool cowardice = false;
    char debugChoice;
    bool debug = false;

    cout << "Would you like to enter debug mode? (y/n)\n\n"; //I have implimented some very ugly looking ways in the code to impliment debug mode. Lazy
    cin >> debugChoice;
    cout << endl;
    if (debugChoice == 'y') {
        debug = true;
    }
    else if (debugChoice == 'n') {
        debug = false;
    }
    else {
        cout << "Invalid input. Defaulting to no debug mode.\n\n";
    }

    this_thread::sleep_for(1000ms);
  
    cout << "Would you like to begin your adventure?\n\n";
    cout << "Press y to begin your adventure.\n";

    char playerChoice;

    cin >> playerChoice;
    cout << endl;

    while (playerChoice != 'y') {
        cout << "You have decided today is not the day to begin your journey.\n\n"; //will keep looping until the player types y

        this_thread::sleep_for(2000ms);
        
        cout << "...\n\n";

        this_thread::sleep_for(2000ms);
        
        cout << "Would you like to embark on your adventure now?\n";
        cout << "Press y to begin your adventure.\n";
        cin >> playerChoice;
    }
    while (playerChoice == 'y') {
        cout << "\tYour adventure begins. The frontier is an uncharted region located near the equator on the continent of Wohul. The local kingdom is currently embroiled in a civil war between the ruling Monarch and a splintered militant faction and cannot afford to dispatch guards around the area. Freelance adventurers are the only real force that consistently ventures into the surrounding jungle. Though monsters do not typically occupy themselves near the borders of civilization, it is best to take precautions. It is probably advisable for any self-respecting adventurer to cut his losses and retreat with their life when needed.\n\n";

        this_thread::sleep_for(2000ms);

        TURN = (rand() % 6 + 5); //took me a bit to get used to it. To do a range on rand, have the range for the modulus + (the minimum number + 1)
        rewardGOLD = TURN;
        rewardEXP = TURN * 2;

        this_thread::sleep_for(2000ms);
      
        cout << "A haggard hound slowly lumbers out of the jungle thicket and onto the path before you. It snarls at you and approaches, mouth foaming.\n\n";

            while (playerHP > 0 && TURN-- > 0) {
                cout << "The beast stands before you\n\n";
                enemyATK = rand() % 4;
                playerBLOCK = rand() % 4;
                if (debug == true) {
                    cout << "This fight can last up to " << TURN << " turns.\n\n";
                }
              
                this_thread::sleep_for(2000ms);
              
                if (enemyATK > playerBLOCK) {
                    if (debug == false) {
                        cout << "The hound bites you!\n\n";
                        playerHP -= (enemyATK - playerBLOCK);

                        this_thread::sleep_for(2000ms);
                  
                        cout << "Your HP status card reads " << playerHP << ".\n\n";

                        this_thread::sleep_for(1000ms);

                        if (playerHP <= 0) {
                            break;
                        } else {
                            cout << "Will you retreat?\n\n";
                            cout << "Press y to retreat.\n";
                            cin >> abandonChoice;
                            if (abandonChoice == 'y') {
                                cout << "You have retreated from the fight.\n\n";
                                cowardice = true;
                                break;
                            } else { 
                                cout << "You stand your ground against this mutt.\n\n";
                                this_thread::sleep_for(1000ms);
                            }
                        }
                    } else {
                        cout << "The hound bites for " << enemyATK << " damage, but you block for " << playerBLOCK << " damage.\n\n";
                        playerHP -= (enemyATK - playerBLOCK);

                        this_thread::sleep_for(2000ms);

                        cout << "Your HP status card reads " << playerHP << ".\n\n";

                        this_thread::sleep_for(1000ms);

                        if (playerHP <= 0) {
                            break;
                        } else {
                            cout << "Will you retreat?\n\n";
                            cout << "Press y to retreat.\n";
                            cin >> abandonChoice;
                            if (abandonChoice == 'y') {
                                cout << "You have retreated from the fight.\n\n";
                                cowardice = true;
                                break;
                            } else { 
                                cout << "You stand your ground against this mutt.\n\n";
                              
                                this_thread::sleep_for(1000ms);
                              
                            }
                        }
                    }
                } else {
                    cout << "You've succefully blocked the hound's attack!\n\n";
                    if (debug == true) {
                        cout << "The hound's attack was " << enemyATK << " damage, but you blocked for " << playerBLOCK << " damage.\n\n";
                    }
                  
                    this_thread::sleep_for(2000ms);
                  
                }
            }
            if (cowardice == false) {
                if (playerHP > 0) {
                    cout << "You've succefully defeated the hound!\n\n";
                    cout << "You've gained " << rewardGOLD << " gold and " << rewardEXP << " EXP from the battle.\n\n";
              
                    playerGOLD += rewardGOLD;
                    playerEXP += rewardEXP;
              
                    this_thread::sleep_for(1000ms);
              
                    cout << "You have now accumulated " << playerGOLD << " gold and " << playerEXP << " EXP.\n\n";

                    this_thread::sleep_for(2000ms);
                  
                    cout << "\tStanding over the dead hound, you notice many previous wounds contributing to its initial haggard appearance. Closer inspection as you reap its corpse for reward indicates that it was previously wounded multiple times as with a needle. These wounds could not have been inflicted by your rusty shortsword. Perhaps it may have been roaming hornets? The thought of being stung by the large insect you've conjured within the mind causes your body to shudder. You take your spoils and go back to the guild hall.\n\n";

                    this_thread::sleep_for(5000ms);

                    cout << "\tReturning to the guildhall with hound hide and meat in tow, you see that the lady you spoke to earlier is still sitting behind the lone desk. As she looks up to you from her book and notices the new material you've acquired, she sets her book down and perks up. She seems to be rummaging through her desk as you approach her. After idling in front of her desk for a moment, she slams a paper form onto the desk in front of you in one continuous motion. She finally greets you and says.\n\n";

                    this_thread::sleep_for(5000ms);

                    cout << "\"Welcome back " << playerName << ", I see your first day in the frontier was bountiful, I am glad to see you have made it back alive! Now, in order to process monster materials for compensation, I will need you to fill out this form.\"\n\n";

                    this_thread::sleep_for(5000ms);

                    cout << "You look at the form... Has paperwork always been a part of this job?";
                      
                    break;
                } else {
                    cout << "You've been defeated... This is where your story ends?" << endl; //Its really hard to actually die in this game, maybe i'm lucky?
                    break;
            }
        } else {
              cout << "You've run away from the hound! You will live to fight another day.\n\n";
              
              this_thread::sleep_for(2000ms);
              
              cout << "\tUpon returning to the guildhall, you see that the lady you spoke to earlier is still sitting behind the lone desk. As she looks up to you from her book, she notices how disappointed you look and sets her book down. She seems to be rummaging through her desk as you approach her. After idling in front of her desk for a moment, she gently places a map of the area from within her desk in front of you. She speaks up,\n\n";

              this_thread::sleep_for(2000ms);
              
              cout << "\"Don't worry about anything. Knowing your limits is a sign of a smart adventurer. I forgot to hand you this map of the currently explored area last time, we don't get too many adventurers here. Please, take it.\"\n\n";

              this_thread::sleep_for(2000ms);

              cout << "\tYou thank her as you take the map and leave the guildhall. Looking down upon it, there seem to be a few areas around the outpost that have been detailed in the sketch form, but it still lacks the confident hand of a cartographer. This journey ahead will be long and arduous for sure.\n\n";
              
              break;
        }
    }
    return 0;
}