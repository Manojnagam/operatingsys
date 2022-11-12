#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct node
{
    char ip[4][20];
}arr[4];

int concat(int a, int b)
{
    char s1[20];
    char s2[20];

    // Convert both the integers to string
    sprintf(s1, "%d", a);
    sprintf(s2, "%d", b);

    // Concatenate both strings
    strcat(s1, s2);

    // Convert the concatenated string
    // to integer
    int c = atoi(s1);

    // return the formed integer
    return c;
}

//validate ip
int validate_number(char *str) {
    while (*str){
        if(!isdigit(*str)){ //if the character is not a number, return 0
         return 0;
        }
        str++; //point to next character
    }
   return 1;
}
int validate_ip(char *ip){ //check whether the IP is valid or not
    int i, num, dots = 0;
    char *ptr;
    if (ip == NULL)
        return 0;
    ptr = strtok(ip, "."); //cut the string using dot delimiter
    if (ptr == NULL)
        return 0;
    while (ptr){
        if (!validate_number(ptr)) //check whether the sub string is valid.
            return 0;
        num = atoi(ptr); //convert substring to number
        if (num >= 0 && num <= 255)
        {
            ptr = strtok(NULL, "."); //cut the next part of the string
            if (ptr != NULL)
                dots++; //increase the dot count
        }
        else
            return 0;
    }
    if (dots != 3) //if the number of dots are not 3, return false
        return 0;
    return 1;
}


int main()
{
    int n[4][4];
    int int_router;  //Intermediate router

    n[0][0]=n[1][1]=n[2][2]=n[3][3]=1;

    n[0][2]=0;
    n[0][1]=n[0][3]=1;

    n[1][0]=n[1][2]=1;
    n[1][3]=0;

    n[2][0]=0;
    n[2][1]=n[2][3]=1;

    n[3][0]=n[3][2]=1;
    n[3][1]=0;

    int i,j,k=4,l;
    printf("Routers are connected like this:\n");
    printf("  1 2 3 4\n");
    for(i=0;i<k;i++)
    {   printf("%d ",i+1);
        for(j=0;j<k;j++)
        {
            printf("%d ",n[i][j]);
        }
        printf("\n");
    }

    int num[4],count=0;
    for(i=0;i<k;i++)
    {
        do
        {
            printf("How many networks are joined to router %d: ",i+1);
            scanf("%d",&num[i]);
            if(num[i]>=0)
                count+=num[i];
        }while(num[i]<0);

    }
    printf("\nTotal number of networks : %d\n",count);
    int flag;
    char* sc=(char*)calloc(1,sizeof(char));
    char sd[count*2][20];
    int* im=(int*)calloc(1,sizeof(int));
    for(i=0;i<k;i++)
    {
        for(j=0;j<num[i];j++)
        {
            do{
                printf("\nEnter router %d Network IP address %d: ",i+1,j+1);
                scanf("%s",arr[i].ip[j]);
                strcpy(sc,arr[i].ip[j]);
                flag = validate_ip(sc);
                if(flag==0){
                    printf("Invalid IP address! Please enter a valid address.\n");
                }
            }while(flag==0);
        }
    }
    printf("\n");
    int check0=0;
    int count0=0;
    do
    {
        char source[20],temp[20],sode[40],sode1[40]={0},source1[20];
        int check;
        int result;
        int router_no,srn;
        do
        {
            printf("Enter source IP address: ");
            scanf("%s",source);
            strcpy(sode,source);
            strcat(sode,"*");
            printf("\n");
            for(i=0;i<=k;i++)
            {
                for(j=0;j<num[i];j++)
                {
                    check=0;
                    strcpy(temp,arr[i].ip[j]);
                    for(l=0;l<strlen(temp);l++)
                    {
                        if(temp[l]!=source[l])
                        {
                            check=1;
                            break;
                        }
                    }
                    if(check==0)
                    {
                        router_no=i+1;
                        goto lable1; 
                    }
                }
            }
            printf("Enter a valid source IP address!\n");
        }while(check==1);

        lable1:
            if(check==0)
            {
                printf("Source router is %d\n",router_no);
            }
            srn=router_no;

            //Destination
            printf("\n");
            char destination[20],destination1[20];
            int check1;
            int result1;
            int router_no1,drn;
            do{
                printf("Enter Destination IP address: ");
                scanf("%s",destination);
                strcat(sode,destination);
                printf("\n");
                for(i=0;i<=k;i++)
                {
                    for(j=0;j<num[i];j++)
                    {
                        check1=0;
                        strcpy(temp,arr[i].ip[j]);
                        for(l=0;l<strlen(temp);l++)
                        {
                            if(temp[l]!=destination[l])
                            {
                                check1=1;
                                break;
                            }
                        }
                        if(check1==0){
                            router_no1=i+1;
                            goto lable2; 
                        }
                    }
                }
                printf("Enter a valid destination IP address!\n");
            }while(check1==1);
        
        lable2:
            if(check1==0)
            {
                printf("Destination router is %d\n",router_no1);
            }
            drn=router_no1;
            int check11=0;
            int final1=0;
            for(int l2=0;l2<=8;l2++)
            {  
                //strcpy(sode1,sd[l2]);
                final1=l2;
                for(int l1=0;l1<18;l1++)
                {
                    if(sode1[l1]!=sode[l1])
                    {
                        check11=1;
                        break;
                    }
                }
                if(check11==0){
                    printf("\n\nRouting details :\n--> Source IP address: %s \n--> Source Router: %d \n--> Destination Router: %d \n--> Destination IP address: %s",source,router_no,router_no1,destination);
                    goto lable5;
                }
            }   
            strcpy(source1,source);
            strcat(source1,"*");
            strcpy(destination1,destination);
            strcat(source1,destination1);
            strcpy(sd[count0],source1);
            strcpy(sode1,sd[count0]);
               
            int don[10]={0};
            int i1=0;
            int i2,i3,i4;
            int con;
            if(n[srn-1][drn-1]==1)
            {
                printf("\nEnter 1 : If you want to choose shortest path for routing purpose\nEnter 0 : To enter intermediate routers\nOption : ");
                scanf("%d",&i4);
                if(i4==1){
                    printf("\n\nRouting details :\n--> Source IP address: %s \n--> Source Router: %d \n--> Destination Router: %d \n--> Destination IP address: %s",source,router_no,router_no1,destination);
                    strcat(source,"*");
                    strcat(source,destination);
                    strcpy(sd[count0],source);
                    printf("\n%s",sd[count0]);
                    con=concat(router_no,router_no1);
                    im[count0]=con;
                    goto lable4;
                }
            }

        lable3:
            do
            {
                printf("\nEnter intermediate router : ");
                scanf("%d",&int_router);
                if(n[srn-1][int_router-1]==1)
                {
                    don[i1]=int_router;
                    i1=i1+1;
                    srn=int_router;
                    if(n[int_router-1][drn-1]==1){
                        printf("\nEnter 1 : To enter more routers\nEnter 0 : To complete the routing process\nOption : ");
                        scanf("%d",&i2);
                        if(i2==0)
                        {
                            i3=(int)(sizeof(don)/sizeof(don[0]));
                            printf("\nInter mediate routers are: ");
                            for(i=0;don[i]!=0;i++){
                                printf("%d ",don[i]);
                            }
                            con=concat(con,router_no1);
                            im[0]=con;
                            printf("\n\nRouting details :\n--> Source IP address: %s \n--> Source Router: %d \n--> Destination Router: %d \n--> Destination IP address: %s",source,router_no,router_no1,destination);
                            strcat(source,"*");
                            strcat(source,destination);
                            strcpy(sd[count0],source);

                            goto lable4;
                        }
                        else
                            goto lable3;
                    }
                    else
                        goto lable3;
                }
                else{
                        printf("\nInvalid router!");
                        goto lable3;
                    }
            }while(n[router_no-1][int_router-1]==0);

        lable4:
            printf("\n\ncompleted!\n");
            for(i=0;don[i]!=0;i++)
            {
                con=concat(router_no,don[i]);
                router_no=con;
            }
            if(i4!=1)
            {
                con=concat(con,router_no1);
            }
            im[count0]=con;
            printf("\nSource Destination details: %s\n",sd[count0]);
            printf("\nStatic route followed : %d\n\n",im[count0]);
       
        lable5:
            if(check11==0)
            {
                printf("\nStatic route followed : %d\n\n",im[final1]);
            }
            printf("Enter 0 : To start another process\nEnter 1 : QUIT\nOption : ");
            scanf("%d",&check0);
            count0=count0+1;
            printf("\n");

    }while(check0==0 && count0<=count);

    free(im);
    free(sc);

    return 0;
}

