#include<stdio.h>
#include<string.h>

typedef struct {
  char fn[50];
  char sn[50];
}
NC;

typedef struct {
  char status;
  char check_in_date[50];
  NC name_client;
  char CIN[50];
  int room_number;
  int night_to_spend;
}
SR;

typedef struct {
  char status;
  char check_in_date[50];
  NC name_client1;
  NC name_client2;
  char CIN1[50];
  char CIN2[50];
  int room_number;
  int status_kid;
  int night_to_spend;
}
DR;

typedef struct {
  char status;
  char check_in_date[50];
  NC name_client1;
  NC name_client2;
  char CIN1[50];
  char CIN2[50];
  int room_number;
  int number_kids;
  int night_to_spend;
}
StR;

void check_out(SR * , DR * , StR * , FILE * );
void check_in(SR * , DR * , StR * , char * , FILE * );
void availability(SR * , DR * , StR * , char * , int * );
void hotel_earnings(FILE * );
void menu(void);

main() {
  int choice;
  int j, k, flag = 0, i;
  SR A[56];
  DR B[56];
  StR C[56];
  char room[50];
  FILE * infp, anfp;
  FILE * outfp;
  int rn = 0;
  char client[50] = "none";

  for (i = 0; i < 5; i++) {
    A[i].status = 'E';
    A[i].room_number = 2 * i + 1;
  }

  for (i = 0; i < 10; i++) {
    B[i].status = 'E';
    B[i].room_number = 2 * i + 2;
  }

  for (i = 0; i < 3; i++) {
    C[i].status = 'E';
    C[i].room_number = 11 * i + 33;
  }

  strcpy(room, "none");
  do {
    menu();
    printf(" Please Input your choice ");
    scanf("%d", & choice);
    switch (choice) {
    case 1: {
      strcpy(room, "none");
      availability(A, B, C, room, & flag);
      break;
    }
    case 2: {
      check_in(A, B, C, & room[0], & infp);
      break;
    }
    case 3: {
      check_out(A, B, C, & outfp);
      break;
    }
    case 4: {
      hotel_earnings( & anfp);
      break;
    }
    case 5: {
      printf(" Done !! ");
      break;
    }
    default: {
      printf(" Invalid Input ");
      break;
    }
    }
  } while (choice != 5);
}

void menu() {
  printf("\n--------------------------------------------------\n");
  printf("\t1. Check availability of a room type\n");
  printf("\t2. Check in\n");
  printf("\t3. Check out\n");
  printf("\t4. Hotel earning\n");
  printf("\t5. Quit\n");
  printf("----------------------------------------------------\n");
}

void availability(SR A[50], DR B[50], StR C[50], char * room, int * flag) {
  int i;
  if (strcmp(room, "none") == 0) {
    printf("Can you please indicate me the room type do you want.(single, double or studio)\n");
    do {
      scanf("%s", room);
      if (strcmp(room, "single") != 0 && strcmp(room, "double") != 0 && strcmp(room, "studio") != 0) {
        printf("Invalid Answer\n");
        printf("Can you please indicate me the room type do you want.(single, double or studio)\n");
      }
    } while (strcmp(room, "single") != 0 && strcmp(room, "double") != 0 && strcmp(room, "studio") != 0);
    if (strcmp(room, "single") == 0) {
      printf("The available single rooms are\n");
      for (i = 0; i < 5; i++) {
        if (A[i].status == 'E') {
          printf("room n:%d  ", A[i].room_number);
          * flag = 1;
        }
      }
      if ( * flag == 0)
        printf("No room found");
    }

    if (strcmp(room, "double") == 0) {
      printf("The available double rooms are\n");
      for (i = 0; i < 10; i++) {
        if (B[i].status == 'E') {
          printf("room n:%d  ", B[i].room_number);
          * flag = 1;
        }
      }
      if ( * flag == 0)
        printf("No room found");
    }

    if (strcmp(room, "studio") == 0) {
      printf("The available studio rooms are\n");
      for (i = 0; i < 3; i++) {
        if (C[i].status == 'E') {
          printf("room n:%d  ", C[i].room_number);
          * flag = 1;
        }
      }

      if ( * flag == 0)
        printf("No room found");
    }

  } else {

    if (strcmp(room, "single") == 0) {
      printf("The available single rooms are\n");
      for (i = 0; i < 5; i++) {
        if (A[i].status == 'E') {
          printf("room n:%d  ", A[i].room_number);
          * flag = 1;
        }
      }
      if ( * flag == 0)
        printf("No room found");
    }

    if (strcmp(room, "double") == 0) {
      printf("The available double rooms are\n");
      for (i = 0; i < 10; i++) {
        if (B[i].status == 'E') {
          printf("room n:%d  ", B[i].room_number);
          * flag = 1;
        }
      }
      if ( * flag == 0)
        printf("No room found");
    }

    if (strcmp(room, "studio") == 0) {
      printf("The available studio rooms are\n");
      for (i = 0; i < 3; i++) {
        if (C[i].status == 'E') {
          printf("room n:%d  ", C[i].room_number);
          * flag = 1;
        }
      }
      if ( * flag == 0)
        printf("No room found");
    }

  }
}

void check_in(SR A[50], DR B[50], StR C[50], char room2[50], FILE * infp) {
  char c, partner;
  char room[50], name1[50];
  int k, l, i, flag = 0, choice;
  printf("Welcome to our hotel !!\n");
  printf("Hello! Can you please indicate me the room type do you want.(single, double or studio)\n");
  do {
    scanf("%s", room);
    if (strcmp(room, "single") != 0 && strcmp(room, "double") != 0 && strcmp(room, "studio") != 0) {
      printf("Invalid Answer\n");
      printf("Can you please indicate me the room type do you want.(single, double or studio)\n");
    }
  } while (strcmp(room, "single") != 0 && strcmp(room, "double") != 0 && strcmp(room, "studio") != 0);

  if (strcmp(room, "single") == 0) {

    availability(A, B, C, room, & flag);
    if (flag = 1) {
      printf("\nMake your choice!");
      do {
        scanf("%d", & choice);
        if (choice % 2 == 0 || choice < 1 || choice > 9 || A[choice].status == 'F')
          printf("Invalid Choice, try again");
      } while (choice % 2 == 0 || choice < 1 || choice > 9 || A[choice].status == 'F');

      for (i = 0; i < 5; i++) {
        if (A[i].room_number == choice) {
          l = i;
          A[i].status = 'F';
        }
      }
      printf("Please input your first name\n");
      scanf("%s", A[l].name_client.fn);
      printf("Please input your family name\n");
      scanf(" %s", A[l].name_client.sn);
      printf("Please input your CIN\n");
      scanf(" %s", A[l].CIN);
      printf("Please indicate the number of nights do you want to stay\n");
      do {
        scanf(" %d", & A[l].night_to_spend);
        if (A[l].night_to_spend <= 0) {
          printf("Invalid Answer\n");
          printf("Please indicate the number of nights do you want to stay\n");
        }
      } while (A[l].night_to_spend <= 0);
      printf("Please input the check in date(DD/MM/YY) \n");
      scanf("%s", A[l].check_in_date);
      for (i = 0; i < 5; i++) {
        if (A[i].room_number == choice)
          k = i;
      }
      strcpy(room2, room);
      strcpy(room, "none");

    }
  }

  if (strcmp(room, "double") == 0) {

    availability(A, B, C, room, & flag);
    if (flag = 1) {
      printf("\nMake your choice!");
      do {
        scanf("%d", & choice);
        if (choice % 2 != 0 || choice < 2 || choice > 20 || B[choice].status == 'F')
          printf("Invalid Choice, try again");
      } while (choice % 2 != 0 || choice < 2 || choice > 20 || B[choice].status == 'F');
      for (i = 0; i < 10; i++) {
        if (B[i].room_number == choice) {
          l = i;
          B[i].status = 'F';
        }
      }
      printf("Please input your first name\n");
      scanf("%s", B[l].name_client1.fn);
      printf("Please input your family name\n");
      scanf(" %s", B[l].name_client1.sn);
      printf("Please input your CIN\n");
      scanf(" %s", B[l].CIN1);
      printf("Do you have a Partner ?(Type Y for Yes, N for No)\n");
      do {
        scanf(" %c", & partner);
        if (partner != 'Y' && partner != 'N') {
          printf("Invalid Answer\n");
          printf("Do you have a Partner ?(Type Y for Yes, N for No)\n");
        }
      } while (partner != 'Y' && partner != 'N');

      if (partner == 'Y') {
        printf("Please input the first name of your partner\n");
        scanf("%s", B[l].name_client2.fn);
        printf("Please input the family name of your partner\n");
        scanf(" %s", B[l].name_client2.sn);
        printf("Please input the CIN of your partner\n");
        scanf(" %s", B[l].CIN2);
      } else {
        strcpy(B[l].name_client2.fn, "None");
        strcpy(B[l].CIN2, "None");
      }
      printf("Please indicate the number of nights do you want to stay\n");
      do {
        scanf("%d", & B[l].night_to_spend);
        if (B[l].night_to_spend <= 0) {
          printf("Invalid Answer\n");
          printf("Please indicate the number of nights do you want to stay\n");
        }
      } while (B[l].night_to_spend <= 0);
      printf("Please input the check in date(DD/MM/YY) \n");
      scanf("%s", B[l].check_in_date);
      printf("Enter the number of kids(in a double room you are allowed to have 1 kid maximum)\n");
      do {
        scanf("%d", & B[l].status_kid);
        if (B[l].status_kid < 0 || B[l].status_kid > 1) {
          printf("Invalid Answer\n");
          printf("Enter the number of kids(in a double room you are allowed to have 1 kid maximum)\n\n");
        }
      } while (B[l].status_kid < 0 || B[l].status_kid > 1);
      for (i = 0; i < 10; i++) {
        if (B[i].room_number == choice)
          k = i;
      }
      strcpy(room2, room);
      strcpy(room, "none");

    }

  }

  if (strcmp(room, "studio") == 0)

  {

    availability(A, B, C, room, & flag);
    if (flag = 1) {
      printf("\nMake your choice!");
      do {
        scanf("%d", & choice);
        if (choice % 11 != 0 || choice < 33 || choice > 55 || C[choice].status == 'F')
          printf("Invalid Choice, try again");
      } while (choice % 11 != 0 || choice < 33 || choice > 55 || C[choice].status == 'F');
      for (i = 0; i < 3; i++) {
        if (C[i].room_number == choice) {
          l = i;
          C[i].status = 'F';
        }
      }
      printf("Please input your first name\n");
      scanf("%s", C[l].name_client1.fn);
      printf("Please input your family name\n");
      scanf(" %s", C[l].name_client1.sn);
      printf("Please input your CIN\n");
      scanf(" %s", C[l].CIN1);
      printf("Do you have a Partner ?(Type Y for Yes, N for No)\n");
      do {
        scanf(" %c", & partner);
        if (partner != 'Y' && partner != 'N') {
          printf("Invalid Answer\n");
          printf("Do you have a Partner ?(Type Y for Yes, N for No)\n");
        }
      } while (partner != 'Y' && partner != 'N');

      if (partner == 'Y') {
        printf("Please input the first name of your partner\n");
        scanf("%s", C[l].name_client2.fn);
        printf("Please input the family name of your partner\n");
        scanf(" %s", C[l].name_client2.sn);
        printf("Please input the CIN of your partner\n");
        scanf(" %s", C[l].CIN2);
      } else {
        strcpy(C[l].name_client2.fn, "None");
        strcpy(C[l].CIN2, "None");
      }
      printf("Please indicate the number of nights do you want to stay\n");
      do {
        scanf("%d", & C[l].night_to_spend);
        if (C[l].night_to_spend <= 0) {
          printf("Invalid Answer\n");
          printf("Please indicate the number of nights do you want to stay\n");
        }
      } while (C[l].night_to_spend <= 0);
      printf("Please input the check in date(DD/MM/YY) \n");
      scanf("%s", C[l].check_in_date);
      printf("Enter the number of kids(in a double room you are allowed to have 3 kids maximum)\n");
      do {
        scanf("%d", & C[l].number_kids);
        if (C[l].number_kids < 0 || C[l].number_kids > 3) {
          printf("Invalid Answer\n");
          printf("Enter the number of kids(in a double room you are allowed to have 3 kids maximum)\n\n");
        }
      } while (C[l].number_kids < 0 || C[l].number_kids > 3);
      for (i = 0; i < 3; i++) {
        if (C[i].room_number == choice)
          k = i;
      }
      strcpy(room2, room);
      strcpy(room, "none");

    }

  }
  infp = fopen("history.txt", "a+");
  if (strcmp(room2, "single") == 0) {
    fprintf(infp, "Client Name\n%s %s\nPartner\nNone\nRoom Type\n%s\nNumber of kids\n0\nNumber of nights\n%d\n", A[k].name_client.fn, A[k].name_client.sn, room2, A[k].night_to_spend);
    fclose(infp);
  } else if (strcmp(room2, "double") == 0) {
    fprintf(infp, "Client Name\n%s %s\nPartner\n%s\nRoom Type\n%s\nNumber of kids\n%d\nNumber of nights\n%d\n", B[k].name_client1.fn, B[k].name_client1.sn, B[k].name_client2.fn, room2, B[k].status_kid, B[k].night_to_spend);
    fclose(infp);
  } else {
    fprintf(infp, "Client Name\n%s %s\nPartner\n%s\nRoom Type\nstudio\nNumber of kids\n%d\nNumber of nights\n%d\n", C[k].name_client1.fn, C[k].name_client1.sn, C[k].name_client2.fn, C[k].number_kids, C[k].night_to_spend);
    fclose(infp);
  }

}
void check_out(SR * A, DR * B, StR * C, FILE * outfp) {
  int rn, i, j;
  char client[50];
  printf("enter your room number");
  do {
    scanf("%d", & rn);
    if (rn < 1 || (rn > 20 && rn % 11 != 0)) {
      printf("Invalid Room Number");
      printf("\nenter a valid room number");
    }
  } while (rn < 1 || (rn > 20 && rn % 11 != 0));

  if (rn < 10 && rn > 0 && rn % 2 != 0) {
    for (j = 0; j < 5; j++) {
      if (A[j].room_number == rn && A[j].status == 'F')
        i = j;
      else if (A[j].room_number == rn && A[j].status == 'E')
        printf("The room number you give me correspond to an empty room");
    }
    A[i].status = 'E';
    strcpy(client, A[i].name_client.fn);
    strcat(client, "_");
    strcat(client, A[i].name_client.sn);
    strcat(client, "_");
    strcat(client, A[i].CIN);
    strcat(client, ".txt");
    outfp = fopen(client, "w");
    fprintf(outfp, "..........................................\n");
    fprintf(outfp, "\nCheck in Date:\n\n%s\n\nClient Name:\n\n%s %s\n\nRoom Type:\n\nsingle\n", A[i].check_in_date, A[i].name_client.fn, A[i].name_client.sn);
    fprintf(outfp, "\nNumber of kids:\n\n0\n\nNumber of nights:\n\n%d\n\nTotal to pay:\n\n%d MAD\n\nThanks for your visit!\n\n", A[i].night_to_spend, (350 * A[i].night_to_spend));
    fclose(outfp);
  } else if (rn < 21 && rn > 1 && rn % 2 == 0) {
    for (j = 0; j < 10; j++) {
      if (B[j].room_number == rn && B[j].status == 'F')
        i = j;
      else if (B[j].room_number == rn && B[j].status == 'E')
        printf("The room number you give me correspond to an empty room");
    }
    B[i].status = 'E';
    strcpy(client, B[i].name_client1.fn);
    strcat(client, "_");
    strcat(client, B[i].name_client1.sn);
    strcat(client, "_");
    strcat(client, B[i].CIN1);
    strcat(client, ".txt");
    outfp = fopen(client, "w");
    fprintf(outfp, "..........................................\n");
    fprintf(outfp, "\nCheck in Date:\n\n%s\n\nClient Name:\n\n%s %s\n\nRoom Type:\n\ndouble\n", B[i].check_in_date, B[i].name_client1.fn, B[i].name_client1.sn);
    fprintf(outfp, "\nNumber of kids:\n\n%d\n\nNumber of nights:\n\n%d\n\nTotal to pay:\n\n%d MAD\n\nThanks for your visit!\n\n", B[i].status_kid, B[i].night_to_spend, (500 * B[i].night_to_spend) + (50 * B[i].status_kid));
    fclose(outfp);
  } else if (rn < 56 && rn > 32 && rn % 11 == 0) {
    for (j = 0; j < 3; j++) {
      if (C[j].room_number == rn && C[j].status == 'f')
        i = j;
      else if (C[j].room_number == rn && C[j].status == 'E')
        printf("The room number you give me correspond to an empty room");
    }

    C[i].status = 'E';
    strcpy(client, C[i].name_client1.fn);
    strcat(client, "_");
    strcat(client, C[i].name_client1.sn);
    strcat(client, "_");
    strcat(client, C[i].CIN1);
    strcat(client, ".txt");
    outfp = fopen(client, "w");
    fprintf(outfp, "..........................................\n");
    fprintf(outfp, "\nCheck in Date:\n\n%s\n\nClient Name:\n\n%s %s\n\nRoom Type:\n\nstudio\n", C[i].check_in_date, C[i].name_client1.fn, C[i].name_client1.sn);
    fprintf(outfp, "\nNumber of kids:\n\n%d\n\nNumber of nights:\n\n%d\n\nTotal to pay:\n\n%d MAD\n\nThanks for your visit!\n\n", C[i].number_kids, C[i].night_to_spend, (700 * C[i].night_to_spend) + (50 * C[i].number_kids));
    fclose(outfp);
  }

}
void hotel_earnings(FILE * infp) {
  int i = 0, j = 0, k = 0, m = 0, cnt = 0, n = 0;
  char line[30], room_type[30];

  infp = fopen("history.txt", "r+");
  if (infp == NULL)
    printf("FILE NOT FOUND");
  else {
    while (!feof(infp)) {
      for (i = 0; i < 10; i++) {
        fgets(line, 20, infp);
        if (i == 5) {
          strcpy(room_type, line);
        }
        if (i == 7) {
          k = atoi(line);
        }
        if (i == 9) {
          n = atoi(line);
        }
      }

      if (strcmp(room_type, "single\n") == 0)
        cnt = cnt + (n * 350);
      else if (strcmp(room_type, "double\n") == 0)
        cnt = cnt + (n * 500 + k * 50);
      else if (strcmp(room_type, "studio\n") == 0)
        cnt = cnt + (n * 700 + k * 50);
    }

    fclose(infp);
    printf("The hotel earnings so far : %d MAD", cnt);
  }
}
