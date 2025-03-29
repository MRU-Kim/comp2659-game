/*
Names 			Talah Al-Zamel, Ethan Sigfusson, Kim Carino 
Course name   	COMP 2659-002
Stage	    	Stage 8
Deadline        March 24, 2024
File name       splash.c
Professor     	Steve Kalmar
*/

void welcomeScreen(){
    unsigned long input = 0; 
    
    int userChoice = MENU_CHOICE_1;
    int prevChoice = userChoice;

    drawArrow(userChoice);

    while (1) { 
        if (hasUserInput()) {
            input = getUserInput();
            prevChoice = userChoice;

            switch (input) {
                case UP_KEY:
                    if (userChoice > MENU_CHOICE_1) {
                        userChoice--;
                    }
                    break;
                case DOWN_KEY:
                    if (userChoice < MENU_CHOICE_2) {
                        userChoice++;
                    }
                    break;
                case ENTER_KEY:
                    selectOption(userChoice);
                    return; 
                case Q_KEY:
                    selectOption(MENU_CHOICE_2); 
                    return;
                default:
                    break;
            }

            clearArrow(prevChoice);
            drawArrow(userChoice);
        }
    }
}

