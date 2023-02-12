/*
 * Program2.c
 *
 *  Created on: Feb 12, 2023
 *      Author: j087n641
 *
 *
 *
 *      BEFORE YOU JUDGE THE CODE, Firstly, it works, secondly, I'm not familiar with c
 *      and am pressed for time, so the best solution i came up with after 7 hours of work
 *      was to create multiple functions with certain values removed.
 *      I tried making a checklist of what was used previously, coudlnt get it to work
 *      I tried making a flag to not use certain values, it would flip the flag at wrong times
 *
 *      Basically, I'm tired and this works :)
 *
 */


#include <stdio.h>


//Define Touchdown, fieldgoal, safety, 2-pt converson, and 1pt field goal
const int TD = 6, FG = 3, S = 2, TD_2PC = 8, TD_FG = 7;

//Base function to call all other branches
void display_combination0(int score, int tds, int fgs, int safeties, int td_2pcs, int td_fg) {
    //If an end has been reached, print the output and return
    if (score == 0) {
        printf("%d TD, %d FG, %d Safety, %d TD + 2pt, %d TD + FG\n", tds, fgs, safeties, td_2pcs, td_fg);
        return;
    }

    if (score >= TD_2PC) {
        display_combination0(score - TD_2PC, tds , fgs, safeties, td_2pcs + 1, td_fg);
    }
    if (score >= TD_FG) {
            display_combination1(score - TD_FG, tds , fgs, safeties, td_2pcs, td_fg + 1);
    }
    if (score >= TD) {
            display_combination2(score - TD, tds + 1, fgs, safeties, td_2pcs, td_fg);
    }
    if (score >= FG) {
            display_combination3(score - FG, tds, fgs + 1, safeties, td_2pcs, td_fg);
    }
    if (score >= S) {
            display_combination4(score - S, tds, fgs, safeties + 1, td_2pcs, td_fg);
    }
}

//Function without TD with 2pc
void display_combination1(int score, int tds, int fgs, int safeties, int td_2pcs, int td_fg) {
    //If an end has been reached, print the output and return
    if (score == 0) {
        printf("%d TD, %d FG, %d Safety, %d TD + 2pt, %d TD + FG\n", tds, fgs, safeties, td_2pcs, td_fg);
        return;
    }
    if (score >= TD_FG) {
            display_combination1(score - TD_FG, tds , fgs, safeties, td_2pcs, td_fg + 1);
    }
    if (score >= TD) {
            display_combination2(score - TD, tds + 1, fgs, safeties, td_2pcs, td_fg);
    }
    if (score >= FG) {
            display_combination3(score - FG, tds, fgs + 1, safeties, td_2pcs, td_fg);
    }
    if (score >= S) {
            display_combination4(score - S, tds, fgs, safeties + 1, td_2pcs, td_fg);
    }
}

//Function without td2pc and tdfg
void display_combination2(int score, int tds, int fgs, int safeties, int td_2pcs, int td_fg) {
    //If an end has been reached, print the output and return
    if (score == 0) {
        printf("%d TD, %d FG, %d Safety, %d TD + 2pt, %d TD + FG\n", tds, fgs, safeties, td_2pcs, td_fg);
        return;
    }

    if (score >= TD) {
            display_combination2(score - TD, tds + 1, fgs, safeties, td_2pcs, td_fg);
    }
    if (score >= FG) {
            display_combination3(score - FG, tds, fgs + 1, safeties, td_2pcs, td_fg);
    }
    if (score >= S) {
            display_combination4(score - S, tds, fgs, safeties + 1, td_2pcs, td_fg);
    }
}

//function without everything above FG
void display_combination3(int score, int tds, int fgs, int safeties, int td_2pcs, int td_fg) {
    //If an end has been reached, print the output and return
    if (score == 0) {
        printf("%d TD, %d FG, %d Safety, %d TD + 2pt, %d TD + FG\n", tds, fgs, safeties, td_2pcs, td_fg);
        return;
    }
    if (score >= FG) {
            display_combination3(score - FG, tds, fgs + 1, safeties, td_2pcs, td_fg);
    }
    if (score >= S) {
            display_combination4(score - S, tds, fgs, safeties + 1, td_2pcs, td_fg);
    }
}

//Function without evertyhing besides Safeties
void display_combination4(int score, int tds, int fgs, int safeties, int td_2pcs, int td_fg) {
    //If an end has been reached, print the output and return
    if (score == 0) {
        printf("%d TD, %d FG, %d Safety, %d TD + 2pt, %d TD + FG\n", tds, fgs, safeties, td_2pcs, td_fg);
        return;
    }
    if (score >= S) {
            display_combination4(score - S, tds, fgs, safeties + 1, td_2pcs, td_fg);
    }
}

// Main function
int main(void) {

    //Create int for score
    int score;
    //loop until break
    while (1) {
        //Ask for a score
        printf("Enter score: ");
        //get score from user
        scanf("%d", &score);

        // if its less than one, stop everything
        if (score <= 1) {
            break;
        }

        //Otherwise, pring possible combination and run the loop
        printf("Possible combinations:\n");
        //Start with everthing function
        display_combination0(score, 0, 0, 0, 0, 0);

    }
    return 0;
}
