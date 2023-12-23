#include<stdio.h>
#include<math.h>

  int k1,j,i,t,s,A[4][150],B[3][3],counter,l,m,m1,m2,m3,nodes_input,pick,nodes_output,i1,i2,i3;
  int flag1,r,initial,r1,high,low,max_trg_vectors,max_validate_vectors,value1,value2,value3;
  int temp,var,g,v,C[4][150],v1,lower,upper,mid,flag,setvalue,counter1,counter2,counter3;
  int max,max_trg_vectors_cls1,max_trg_vectors_cls2,max_trg_vectors_cls3,s1,validation,hit;
  int mtv1,mtv2,mtv3,max_test_vectors_cls1,max_test_vectors_cls2,max_test_vectors_cls3;
  char str[10];  
  float c;

    FILE *fp1;
    FILE *fp2;
    FILE *fp3;
    FILE *fp4;
    FILE *fp;

    void random_choosing(void);
    void write_in_file(void); 
    void select_and_write(void); 

    void random_choosing()
     {
       l=0;
      while(l<nodes_output)
       {
           if(validation==1)
              {
                if(l==0)
                   j=mtv1;
                if(l==1)
                   j=mtv2;
                if(l==2)  
                   j=mtv3;
               }
            else
               j=initial+1;

             if(setvalue==1)
                {
                 if(l==0)
                  {
                   m=m1;
                   r=max_trg_vectors_cls1;
                   }
                  else if(l==1)
                   {
                     m=m2;
                     r=max_trg_vectors_cls2;
                    }
                   else 
                    {
                      m=m3;   
                      r=max_trg_vectors_cls3;
                     }
                    }
               if(setvalue==2)
                {
                 if(l==0)
                  {
                   m=m1;
                   r=max_trg_vectors_cls1;
                   }
                  else 
                   {
                     m=m2;
                     r=max_trg_vectors_cls2;
                    }
                   }

               if(setvalue==3)
                {
                 if(l==0)
                  {
                   m=m1;
                   r=max_trg_vectors_cls1;
                   }
                  else if(l==1)
                   {
                     m=m2;
                     r=max_trg_vectors_cls2;
                    }
                   else 
                    {
                      m=m3;   
                      r=max_trg_vectors_cls3;
                     }
                    }

              counter=0;
         while(counter!=r)
           {
           flag1=0;
             k1=rand()%(high-low+1)+low;
    
              if(k1>m)
                k1=k1%m;

              if(k1==0)
                 continue;  
    
               for(i=0;i<j;i++)
                 {
                 if(A[l][i]==k1)
                    {
                     flag1=1;               
                     break;
                    } 
                   }

              if(flag1==1)
               {
                continue;
                }
             else
               {
               if(A[l][i-1]==-1)
                   {
                    A[l][i-1]=k1;
                    counter++;
                    } 
               else
                 {
                    A[l][i]=k1;
                    counter++;
                  } 
                }
            j++;
           }
        l++;
       } 
      }  //random_choosing()

    void write_in_file()
     {
       if(l==0)
         fp=fp1;
       if(l==1)
          fp=fp3;
       if(l==2)
          fp=fp4;
       for(s=0;s<nodes_input*(pick-1);s++)
           fscanf(fp,"%f",&c);

        for(s=0;s<nodes_input;s++)
         {
          fscanf(fp,"%f",&c);
          fprintf(fp2,"%f",c);
          fprintf(fp2," ");
          }   
         fprintf(fp2,"\n");

        for(t=0;t<nodes_output;t++)
          {
          fprintf(fp2,"%d",B[l][t]);
           fprintf(fp2," ");
          }
          fprintf(fp2,"\n");
         rewind(fp);
        }//write_in_file()

     void select_and_write()
      {
         s1=0,counter1=0,counter2=0,counter3=0;
        while(s1<max)
         {
          l=0;
          while(l<nodes_output)
             {
              if(setvalue==1)
               {
                if((l==0)&&(counter1!=max_trg_vectors_cls1))
                 {
                  pick=A[l][i1];
                  counter1++;
                  i1++; 
                  write_in_file();
                  }
                 if((l==1)&&(counter2!=max_trg_vectors_cls2))
                  {
                    pick=A[l][i2];
                    counter2++;
                    i2++; 
                    write_in_file();
                   }
                  if((l==2)&&(counter3!=max_trg_vectors_cls3))
                   {
                     pick=A[l][i3];
                     counter3++;
                     i3++; 
                     write_in_file();
                    }
                   }
            if(setvalue==2)
               {
                if((l==0)&&(counter1!=max_trg_vectors_cls1))
                 {
                  pick=A[l][i1];
                  counter1++;
                  i1++; 
                  write_in_file();
                  }
                 if((l==1)&&(counter2!=max_trg_vectors_cls2))
                  {
                    pick=A[l][i2];
                    counter2++;
                    i2++; 
                    write_in_file();
                   }
                  }
            if(setvalue==3)
               {
                if((l==0)&&(counter1!=max_trg_vectors_cls1))
                 {
                  pick=A[l][i1];
                  counter1++;
                  i1++; 
                  write_in_file();
                  }
                 if((l==1)&&(counter2!=max_trg_vectors_cls2))
                  {
                    pick=A[l][i2];
                    counter2++;
                    i2++; 
                    write_in_file();
                   }
                  if((l==2)&&(counter3!=max_trg_vectors_cls3))
                   {
                     pick=A[l][i3];
                     counter3++;
                     i3++; 
                     write_in_file();
                    }
                   }
                l++;
              }
            s1++;
           }
         }//select_and_write() 
 
       
void main()
 {
    for(i=0;i<4;i++)
       {
       for(j=0;j<150;j++)
        {
         A[i][j]=-1;
         }
        }
       
     for(i=0;i<4;i++)
       {
       for(j=0;j<150;j++)
        {
         C[i][j]=-1;
         }
        }  

    printf("\n enter the name of the data set\n");
    scanf("%s",str);
    
    value1=strcmp(str,"iris");
     if(value1==0)
       setvalue=1;

    value2=strcmp(str,"habermans");
      if(value2==0)
         setvalue=2;

    value3=strcmp(str,"teaching");
     if(value3==0)
          setvalue=3;
    
if(setvalue==1)
     {
   printf("\n enter the max no.of vectors in class1 file\n");
   scanf("%d",&m1);
   printf("\n enter the max no.of vectors in class2 file\n");
   scanf("%d",&m2);
   printf("\n enter the max no.of vectors in class3 file\n");
   scanf("%d",&m3);

   printf("\n enter the no.of nodes in input layer\n");
   scanf("%d",&nodes_input);
   printf("\n enter the no.of nodes in output layer\n");
   scanf("%d",&nodes_output);

     if((fp1=fopen("Iris_class1","r"))==NULL)
       printf("Can't open the file\n");
   
     if((fp3=fopen("Iris_class2","r"))==NULL)
       printf("Can't open the file\n");
 
     if((fp4=fopen("Iris_class3","r"))==NULL)
       printf("Can't open the file\n");
      } 

   else if(setvalue==2)
     {
    printf("\n enter the max no.of vectors in class1 file\n");
    scanf("%d",&m1);
    printf("\n enter the max no.of vectors in class2 file\n");
    scanf("%d",&m2);
   
    printf("\n enter the no.of nodes in input layer\n");
    scanf("%d",&nodes_input);
    printf("\n enter the no.of nodes in output layer\n");
    scanf("%d",&nodes_output);

     if((fp1=fopen("habermans_class1","r"))==NULL)
       printf("Can't open the file\n");
   
     if((fp3=fopen("habermans_class2","r"))==NULL)
       printf("Can't open the file\n");
      } 
  else 
     {
   printf("\n enter the max no.of vectors in class1 file\n");
   scanf("%d",&m1);
   printf("\n enter the max no.of vectors in class2 file\n");
   scanf("%d",&m2);
   printf("\n enter the max no.of vectors in class3 file\n");
   scanf("%d",&m3);

   printf("\n enter the no.of nodes in input layer\n");
   scanf("%d",&nodes_input);
   printf("\n enter the no.of nodes in output layer\n");
   scanf("%d",&nodes_output);

     if((fp1=fopen("teaching_class1","r"))==NULL)
       printf("Can't open the file\n");
   
     if((fp3=fopen("teaching_class2","r"))==NULL)
       printf("Can't open the file\n");
 
     if((fp4=fopen("teaching_class3","r"))==NULL)
       printf("Can't open the file\n");
      } 
   printf("\n enter the value of high\n");
   scanf("%d",&high);
   printf("\n enter the value of low\n");
   scanf("%d",&low);
   
    for(i=0;i<nodes_output;i++)
       {
          var=i+1;
      printf("\n give the desired output for class:%d\n",var);
       for(j=0;j<nodes_output;j++)
        {
         scanf("%d",&B[i][j]);
         }
        }
     //printf("\n hello\n");

    if(setvalue==1)
     {
       //printf("\n hello\n");
      printf("\n enter the max no.of vectors in training file from class 1\n");
      scanf("%d",&max_trg_vectors_cls1);
      printf("\n enter the max no.of vectors in training file from class 2\n");
      scanf("%d",&max_trg_vectors_cls2);
      printf("\n enter the max no.of vectors in training file from class 3\n");
      scanf("%d",&max_trg_vectors_cls3);
      printf("\n hello\n");
 max=max_trg_vectors_cls1>max_trg_vectors_cls2 ? max_trg_vectors_cls1:max_trg_vectors_cls2;
 max=max>max_trg_vectors_cls3 ? max:max_trg_vectors_cls3;
    printf("\n  the max value is for class:%d\n",max);
      printf("\n hello\n");
     }
    else if(setvalue==2)
     {
       printf("\n enter the max no.of vectors in training file from class 1\n");
       scanf("%d",&max_trg_vectors_cls1);
       printf("\n enter the max no.of vectors in training file from class 2\n");
       scanf("%d",&max_trg_vectors_cls2);
  max=(max_trg_vectors_cls1>max_trg_vectors_cls2)?max_trg_vectors_cls1:max_trg_vectors_cls2;
      }
    else
       {
        printf("\n enter the max no.of vectors in training file from class 1\n");
        scanf("%d",&max_trg_vectors_cls1);
        printf("\n enter the max no.of vectors in training file from class 2\n");
        scanf("%d",&max_trg_vectors_cls2);
        printf("\n enter the max no.of vectors in training file from class 3\n");
        scanf("%d",&max_trg_vectors_cls3);
   max=(max_trg_vectors_cls1>max_trg_vectors_cls2)?max_trg_vectors_cls1:max_trg_vectors_cls2;
   max=(max>max_trg_vectors_cls3)?max:max_trg_vectors_cls3;
      //printf("\n give the max value is for class:%d\n",max);
       }
        
       

    //formation of training file

       if((fp2=fopen("training","w"))==NULL)
       printf("Can't open the file\n");

         mtv1=max_trg_vectors_cls1;
         mtv2=max_trg_vectors_cls2;
         mtv3=max_trg_vectors_cls3; 

      initial=0;
      i1=initial;
      i2=initial;
      i3=initial;
      random_choosing();
      select_and_write();
      fclose(fp2);

  ///formation of validation file

               
      if((fp2=fopen("validate","w"))==NULL)
            printf("Can't open the file\n");

        
      max_trg_vectors_cls1=0;
      max_trg_vectors_cls2=0;
      max_trg_vectors_cls3=0;

   if(setvalue==1)
     {
      printf("\n enter the max no.of vectors in validation file from class 1\n");
      scanf("%d",&max_trg_vectors_cls1);
      printf("\n enter the max no.of vectors in validation file from class 2\n");
      scanf("%d",&max_trg_vectors_cls2);
      printf("\n enter the max no.of vectors in validation file from class 3\n");
      scanf("%d",&max_trg_vectors_cls3);
   max=(max_trg_vectors_cls1>max_trg_vectors_cls2)?max_trg_vectors_cls1:max_trg_vectors_cls2;
   max=(max>max_trg_vectors_cls3)?max:max_trg_vectors_cls3;
  //printf("\n  the max value for validate is for class:%d\n",max);
     }
    else if(setvalue==2)
     {
       printf("\n enter the max no.of vectors in validation file from class 1\n");
       scanf("%d",&max_trg_vectors_cls1);
       printf("\n enter the max no.of vectors in validation file from class 2\n");
       scanf("%d",&max_trg_vectors_cls2);
  max=(max_trg_vectors_cls1>max_trg_vectors_cls2)?max_trg_vectors_cls1:max_trg_vectors_cls2;
      }
    else
       {
        printf("\n enter the max no.of vectors in validation file from class 1\n");
        scanf("%d",&max_trg_vectors_cls1);
        printf("\n enter the max no.of vectors in validation file from class 2\n");
        scanf("%d",&max_trg_vectors_cls2);
        printf("\n enter the max no.of vectors in validation file from class 3\n");
        scanf("%d",&max_trg_vectors_cls3);
   max=(max_trg_vectors_cls1>max_trg_vectors_cls2)?max_trg_vectors_cls1:max_trg_vectors_cls2;
   max=(max>max_trg_vectors_cls3)?max:max_trg_vectors_cls3;
       }

             validation=1;
             
             random_choosing();
             select_and_write();
             fclose(fp2);


               //formation of test file

   
         if((fp2=fopen("test","w"))==NULL)
               printf("Can't open the file\n");
        
        
             
           
                 //sorting the array A[][]   
         for(s=0;s<nodes_output;s++)
            {
              printf("\n Hello test,s is:%d\n",s);
                if(s==0)
                 {
                   max_trg_vectors=mtv1;
                   max_validate_vectors=max_trg_vectors_cls1;
                 }
                if(s==1)
                  {
                    max_trg_vectors=mtv2;
                    max_validate_vectors=max_trg_vectors_cls2;
                   }
                 if(s==2)
                   {
                     max_trg_vectors=mtv3;
                     max_validate_vectors=max_trg_vectors_cls3;
                    }
             for(i=0;i<max_trg_vectors+max_validate_vectors;i++)
              {
               for(j=0;j<max_trg_vectors+max_validate_vectors-i-1;j++)
                {
                 if(A[s][j]>A[s][j+1])
                  {
                     temp=A[s][j];
                     A[s][j]=A[s][j+1];
                     A[s][j+1]=temp;
                   }
                  }
                 }
                }

 //binary search on arrayA[][]
          l=0;
   while(l<nodes_output)
    {
       if(l==0)
        { 
         m=m1;
         upper=i1-1;
        }  
       if(l==1)
        {
         m=m2;
         upper=i2-1;
        } 
       if(l==2)
        {
         m=m3;
         upper=i3-1;
         }

        j=0;
      for(g=1;g<=m;g++)
       {
         lower=0,i=-1,flag=1;
         
        while(upper>=lower)
        {
          mid=(upper+lower)/2;
          if(g==A[l][mid])
           {
            i=mid;
            flag=0;
            break;
           }
          else
            {
             if(g>A[l][mid])
               lower=mid+1;
             else
               upper=mid-1;
             }
           }
          if(flag==1)
            {
             C[l][j]=g;
             j=j+1;
            }
           }//for g
          l++;
          }//while l loop 

// -----------------binary search finished---------------------//

   //picking values from C & writing to test file

    if(setvalue==1)
     {
       if(l==0)
         m=m1;
       if(l==1)
         m=m2;
       if(l==2)
         m=m3;
     max_test_vectors_cls1=m1-(mtv1+max_trg_vectors_cls1);
     max_test_vectors_cls2=m2-(mtv2+max_trg_vectors_cls2);
     max_test_vectors_cls3=m3-(mtv3+max_trg_vectors_cls3);  
max=(max_test_vectors_cls1>max_test_vectors_cls2)?max_test_vectors_cls1:max_test_vectors_cls2;  
 max=(max>max_test_vectors_cls3)?max:max_test_vectors_cls3;
  //printf("\nthe max value for test is :%d\n",max);
     }

    else if(setvalue==2)
     {
       if(l==0)
        m=m1;
       if(l==1)
         m=m2;
 max_test_vectors_cls1=m1-(mtv1+max_trg_vectors_cls1);
 max_test_vectors_cls2=m2-(mtv2+max_trg_vectors_cls2);
 //printf("\nthe max value for test is :%d\n",max);
 max=(max_test_vectors_cls1>max_test_vectors_cls2)?max_test_vectors_cls1:max_test_vectors_cls2;
  // printf("\nthe max value for test is :%d\n",max);
   //printf("\nthe max value for test is :%d\n",max_test_vectors_cls2);
   //printf("\nthe max value for test is :%d\n",max_test_vectors_cls1);
   }

    else
       {
        if(l==0)
         m=m1;
       if(l==1)
         m=m2;
        if(l==2)
         m=m3;
 max_test_vectors_cls1=m1-(mtv1+max_trg_vectors_cls1);
max_test_vectors_cls2=m2-(mtv2+max_trg_vectors_cls2);
max_test_vectors_cls3=m3-(mtv3+max_trg_vectors_cls3); 
max=(max_test_vectors_cls1>max_test_vectors_cls2)?max_test_vectors_cls1:max_test_vectors_cls2;  
 max=(max>max_test_vectors_cls3)?max:max_test_vectors_cls3;
       }

        counter=0,hit=0;
          //printf("\n Hello test,s is:%d\n",s);
         while(counter!=max)
           {
             l=0;
           // printf("\n Hello test,counter is:%d\n",counter);
            while(l<nodes_output)
             {
              pick=C[l][counter];
               if(pick!=-1)
                 {
                  write_in_file();
                  hit++;
                 }
              l++;
              }
             counter++;
            } //while(counter)
           printf("\n Hello test,hit is:%d\n",hit);
                
              for(i=0;i<2;i++)
               {
                 printf(" ");
               for(j=0;j<75;j++)
                 {
                  printf("\n%d",C[i][j]);
                  }
                 }
    
     fclose(fp1);
     fclose(fp2);
     fclose(fp3);
     fclose(fp4);
  }//main closes

