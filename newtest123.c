#include<stdio.h>
#include<math.h>
float input_weights[200][6],hidden_weights[3][200];
float desired_output[3],input_trg_set[6][1],input_to_hidden[200][1];
float output_of_hidden[200][1],input_to_output[3][1],output_of_output[3][1];
float error[3],weight_correction_output[3][200],weight_correction_input[6][200];
float del_1[3][1],del_2[200][1],transpose_del_1[1][3],transpose_del_2[1][200];
float transpose_output_of_hidden[1][200],transpose_weight_correction_input[200][5],lamda,a,sum=0.0,err[3],set_of_errors[60],transpose_hidden_weights[200][3];
int i,j,k,nodes_input,nodes_output,nodes_hidden,no_of_trg_sets,counter,iterations,flag,mark,t,g,hit,count,no_of_validate_set;
float tolerance,sum_error,avg_error,sum_validate,c,d,final_errors[45],final_error,avg_final_error,k1,k2;
int no_of_test_sets,v,sign,limit,high,low,setvalue=0;
FILE *fp1;
FILE *fp;
FILE *fp3;
void train(void);
void validate(void);
void test(void);
void input(void);
void input_validate_set(void);
void input_training_set(void);
void input_test_set(void);
void calculate_input_to_hidden_layer(void);
void calculate_output_of_hidden_layer(void);
void calculate_input_to_output_layer(void);
void calculate_output_of_output_layer(void);
void calculate_error(void);
void weight_adjustment(void);
void new_weights(void);
float sigmoid(float);
float sigmoid(float x)
 {
  k1=(1+exp(-a*x));
  k2=pow(k1,-1);
  return(k2);
  }
void input()
{
 
  // input weights 
   
 for(i=0;i<nodes_hidden;i++)
 {
  for(j=0;j<nodes_input;j++)
   {
     /*limit=rand()%(high-low+1)+low;
      sign=pow(-1,limit);*/
      c=rand();
      while(c>1)
       {
        //m=c%10;
        c=c/10000;
        }  
     input_weights[i][j]=c;
     //printf(" \n the value of c is:%f\n",c);
     }
   }

 // hidden weights
     
  for(i=0;i<nodes_output;i++)
   {                           
   for(j=0;j<nodes_hidden;j++)
    {
      /*limit=rand()%(high-low+1)+low;
      sign=pow(-1,limit);*/
      d=rand();
       while(d>1)
       {
        //m=c%10;
        d=d/10000;
        }  
      hidden_weights[i][j]=d;
      //printf(" \n the value of c is:%f\n",c);
     }
    }



     /*printf("\n the randomly selected input synaptic weights\n");     
     for(i=0;i<nodes_hidden;i++)
      {
       printf("\n"); 
      for(j=0;j<nodes_input;j++)
       {
        printf("  ");  
        printf("%f",input_weights[i][j]);
        }
       }
      printf("\n");
      printf(" \n");

      printf("\n the randomly selected hidden synaptic weights\n");      
      for(i=0;i<nodes_output;i++)
        { 
         printf("\n");                          
       for(j=0;j<nodes_hidden;j++)
         {
          printf("  "); 
          printf("%f",hidden_weights[i][j]);
         }
        }*/
    
 }//end of function

void input_training_set()
 {
  //printf("\n enter the training data set:\n");
   for(i=0;i<nodes_input;i++)
    {
    for(j=0;j<1;j++)
     {
     fscanf(fp,"%f",&input_trg_set[i][j]);
     }
    }
  //printf("enter the desired output:\n");
   for(i=0;i<nodes_output;i++)
    {
     fscanf(fp,"%f",&desired_output[i]);
     }
    }//e.o.funtion

 void input_validate_set()
 {
  //printf("\n enter the training data set:\n");
   for(i=0;i<nodes_input;i++)
    {
    for(j=0;j<1;j++)
     {
     fscanf(fp1,"%f",&input_trg_set[i][j]);
     }
    }
  //printf("enter the desired output:\n");
   for(i=0;i<nodes_output;i++)
    {
     fscanf(fp1,"%f",&desired_output[i]);
     }
    }//e.o.funtion


void input_test_set()
 {
  //printf("\n enter the training data set:\n");
   for(i=0;i<nodes_input;i++)
    {
    for(j=0;j<1;j++)
     {
     fscanf(fp3,"%f",&input_trg_set[i][j]);
     }
    }
  //printf("enter the desired output:\n");
   for(i=0;i<nodes_output;i++)
    {
     fscanf(fp3,"%f",&desired_output[i]);
     }
    }//e.o.funtion


void calculate_input_to_hidden_layer()
 {
    sum=0.0;
  for(i=0;i<nodes_hidden;i++)
   {
    for(k=0;k<1;k++)
    {
     for(j=0;j<nodes_input;j++)
      {
      sum=sum+input_weights[i][j]*input_trg_set[j][k];
      input_to_hidden[i][k]=sum;
       }
      sum=0.0;
      }
     }
      /* if(setvalue==1)
        for(i=0;i<nodes_hidden;i++)
         {
         for(k=0;k<1;k++)
          { 
     printf("\n the input to hidden layer for hidden node%d=%f\n",i,input_to_hidden[i][k]);
           }
          }*/ 

       }//end of function

void calculate_output_of_hidden_layer()
 {
  for(i=0;i<nodes_hidden;i++)
    {
    for(j=0;j<1;j++)
     {
     output_of_hidden[i][j]=sigmoid(input_to_hidden[i][j]);
       /*if(setvalue==1)
     printf("\n the output of hidden for hidden node%d=%f\n",i,output_of_hidden[i][j]);*/
      }
     }
    }//eof

void calculate_input_to_output_layer()
 {
    sum=0.0;
  for(i=0;i<nodes_output;i++)
   {
    for(k=0;k<1;k++)
    {
     for(j=0;j<nodes_hidden;j++)
      {
      sum=sum+hidden_weights[i][j]*output_of_hidden[j][k];
       input_to_output[i][k]=sum;
       }
      sum=0.0;
      }
     }
       /*if(setvalue==1)
        for(i=0;i<nodes_output;i++)
          {
         for(k=0;k<1;k++)
           { 
           printf("\n the input to output for node%d=%f\n",i,input_to_output[i][k]);
            }
           }*/ 
         }//eof

void calculate_output_of_output_layer()
 {
  for(i=0;i<nodes_output;i++)
   {
    for(j=0;j<1;j++)
    {
     output_of_output[i][j]=sigmoid(input_to_output[i][j]);
       /*if(setvalue==1)
        printf("\n the total output for this node=%f\n", output_of_output[i][j]);*/
     }
    }
   }//eof

void calculate_error()
 {
   sum_error=0.0;
  for(i=0;i<nodes_output;i++)
   {
    for(j=0;j<1;j++)
     {
     err[i]=(desired_output[i]-output_of_output[i][j]);
      /*if(setvalue==1)
           printf("\n the total error for this iteration=%f \n", err[i]);*/
     error[i]=err[i]*err[i];
     error[i]=error[i]/2;
     sum_error=sum_error+error[i];
     }
    }
   sum_error=((sum_error)/(nodes_output));
  //printf("\n the total error for this iteration=%f \n",sum_error);
  }//eof

void weight_adjustment()
 {
  for(i=0;i<nodes_output;i++)
   {
    for(j=0;j<1;j++)
    {
  del_1[i][j]=lamda*output_of_output[i][j]*(1-output_of_output[i][j])*err[i];
    }
   }
  
  for(i=0;i<nodes_hidden;i++)
   {
    for(j=0;j<1;j++)
    {
     transpose_output_of_hidden[j][i]=output_of_hidden[i][j];
     }
    }
      
       sum=0.0;
  for(i=0;i<nodes_output;i++)
   {
    for(k=0;k<nodes_hidden;k++)
    {
     for(j=0;j<1;j++)
      {
       sum=sum+del_1[i][j]*transpose_output_of_hidden[j][k];
         //sum=sum+del_1[i][j]*transpose_input_to_hidden[j][k];
       weight_correction_output[i][k]=sum;
       }
      sum=0.0;
     }
    }

  //weight correction for hidden layer

   for(i=0;i<nodes_output;i++)
   {
    for(j=0;j<nodes_hidden;j++)
    {
     transpose_hidden_weights[j][i]=hidden_weights[i][j];
    }
   }
   
      sum=0.0;
   for(i=0;i<nodes_hidden;i++)
   {
    for(k=0;k<1;k++)
    {
     for(j=0;j<nodes_output;j++)
     {
       sum=sum+transpose_hidden_weights[i][j]*del_1[j][k];
         del_2[i][k]=sum;
      }
      sum=0.0;
     }
    }


   /* printf("\n the new del_2 matrix is:\n");      
      for(i=0;i<nodes_hidden;i++)
        { 
         printf("\n");                          
       for(j=0;j<1;j++)
         {
          printf("  "); 
          printf("%f",del_2[i][j]);
         }
        }*/
    
    for(i=0;i<nodes_hidden;i++)
     {
     for(j=0;j<1;j++)
      { 
      del_2[i][j]=del_2[i][j]*output_of_hidden[i][j]*(1-output_of_hidden[i][j]);
       }
      }

  for(i=0;i<nodes_hidden;i++)
   {
   for(j=0;j<1;j++)
    {
    transpose_del_2[j][i]=del_2[i][j];
    }
   }
 
      sum=0.0;
  for(i=0;i<nodes_input;i++)
   {
    for(k=0;k<nodes_hidden;k++)
    {
     for(j=0;j<1;j++)
     { 
      sum=sum+input_trg_set[i][j]*transpose_del_2[j][k];
        weight_correction_input[i][k]=sum;
      } 
      sum=0.0;
     }
    }   
     
   }//eof

 void new_weights()
  {
  for(i=0;i<nodes_input;i++)
   {
    for(j=0;j<nodes_hidden;j++)
    {
    transpose_weight_correction_input[j][i]=weight_correction_input[i][j];
     }
    }

 //finding new hidden weights
  for(i=0;i<nodes_output;i++)
    {
     for(j=0;j<nodes_hidden;j++)
      {
  hidden_weights[i][j]=hidden_weights[i][j]+weight_correction_output[i][j];
      }
     }

//finding new input synaptic weights
 
 for(i=0;i<nodes_hidden;i++)
 {
  for(j=0;j<nodes_input;j++)
   {
input_weights[i][j]=input_weights[i][j]+lamda*transpose_weight_correction_input[i][j];
   }
  }
}//eof
 
void train()
{ 
   
  if((fp=fopen("training","r"))==NULL)
      printf("Cannot open the file \n");
  input();
  iterations=0,flag=0;
  while(flag>=0)
   {
     counter=0,hit=0,mark=0;
   while(counter<no_of_trg_sets)
    {
    input_training_set();
    calculate_input_to_hidden_layer();
    calculate_output_of_hidden_layer();
    calculate_input_to_output_layer();
    calculate_output_of_output_layer();
    calculate_error();
    //printf("the total error for this iteration=%f",sum_error);
     if(sum_error>=tolerance)
      {
      weight_adjustment();
      new_weights();
       }
     if(sum_error<tolerance)
        {
          mark=1; 
         // printf("\n%d\n",flag);
          set_of_errors[counter]=sum_error;
          hit=hit+1;
         }
        iterations++;
       counter++;
        }
         if((mark==1)&&(hit==no_of_trg_sets))
           {
            // printf("\n all the training vectors converged\n");
             break;
            }
          flag=flag+1;
       }  
    //fclose(fp);
    }//e.o.function

void validate()
 {
  while(nodes_hidden<=8)
   {
    train();
     printf("\n no.of nodes in hidden layer is:%d\n",nodes_hidden);
        if((fp1=fopen("validate","r"))==NULL)
          printf("Cannot open the file \n");
       //printf("\n hello\n");
        count=0,sum_validate=0.0,setvalue=1;
       while(count<no_of_validate_set)
       {
         input_validate_set();
         input_training_set();
         calculate_input_to_hidden_layer();
         calculate_output_of_hidden_layer();
         calculate_input_to_output_layer();
         calculate_output_of_output_layer();
         calculate_error();  
         sum_validate=sum_validate+sum_error;
         count++;
         //printf("\n the sum error is:%f\n",sum_error); 
        }
        avg_error=(sum_validate)/(no_of_validate_set);
       printf("\n the avg validation error is:%f\n",avg_error);
       if(avg_error<0.01)
          {
          printf("\n all the vectors validated\n");
         break;
          }
       else
         nodes_hidden=nodes_hidden+1;
        }
      //fclose(fp1);
     }//e.o.function

void test()
 {
  if((fp3=fopen("test","r"))==NULL)
     printf("\n Can't open the file \n");

      //printf("\n hello_test\n");

   final_error=0.0;
   for(v=0;v<no_of_test_sets;v++)
    {
    input_test_set();
    calculate_input_to_hidden_layer();
    calculate_output_of_hidden_layer();
    calculate_input_to_output_layer();
    calculate_output_of_output_layer();
    calculate_error();
    final_errors[i]=sum_error;
    final_error=final_error+sum_error;
    //printf("\n hello_test_insideloop\n");
    }
   avg_final_error=(final_error/no_of_test_sets);
   fclose(fp3);
   printf("\n average test error is:%f\n",avg_final_error);
  }//e.o.funtion test()

            
void main()
 {
      
    printf("enter no.of nodes in input layer:");
    scanf("%d",&nodes_input);
    printf("enter no.of nodes in hidden layer:");
    scanf("%d",&nodes_hidden);
    printf("enter no.of nodes in output layer:");
    scanf("%d",&nodes_output);

    printf("enter the value of a:\n");
    scanf("%f",&a);
    printf("enter the value of tolerance:\n");
    scanf("%f",&tolerance); 
    printf("enter the value of lamda:\n");
    scanf("%f",&lamda);
 
    printf("enter the number of training sets :\n");
    scanf("%d",&no_of_trg_sets);
    printf("enter the number of validation sets :\n");
    scanf("%d",&no_of_validate_set);
    printf("enter the number of test sets :\n");
    scanf("%d",&no_of_test_sets);
    printf("enter the value of high :\n");
    scanf("%d",&high);
    printf("enter the value of low:\n");
    scanf("%d",&low);
   
    // train();
    validate();
    test();

   printf("\n the final architecture is:\n");
   printf("\n the no.of nodes in input layer is:%d",nodes_input);
   printf("\n the no.of nodes in hidden layer is:%d",nodes_hidden-1);
   printf("\n the no.of nodes in output layer is:%d",nodes_output);

   
 
   /* printf("\n the new input synaptic weights\n");     
     for(i=0;i<nodes_hidden-1;i++)
      {
       printf("\n"); 
      for(j=0;j<nodes_input;j++)
       {
        printf("  ");  
        printf("%f",input_weights[i][j]);
        }
       }
      printf("\n");
      printf(" \n");

      printf("\n the new hidden synaptic weights\n");      
      for(i=0;i<nodes_output;i++)
        { 
         printf("\n");                          
       for(j=0;j<nodes_hidden-1;j++)
         {
          printf("  "); 
          printf("%f",hidden_weights[i][j]);
         }
        }*/

        printf(" \n "); 
        fclose(fp);

   /*printf("\nthe total no.of iterations are:%d\n",iterations);
   for(i=0;i<no_of_trg_sets;i++)
    {
     printf("\n%f",set_of_errors[i]);
     }*/

   }//end of main
