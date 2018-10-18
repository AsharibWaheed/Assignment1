#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

void function(int *Arr, int size)
{
	int i;
	for(i=0;i<size;i++) Arr[i]=i;
}

int main()
{
	int Arr[1000],index,var1,var2,var3,var4,var5,var6,var7,var8,var9,var10,sum,status;
	function(Arr, 1000);
	int fd1[2],fd2[2],fd3[2],fd4[2],fd5[2],fd6[2],fd7[2],fd8[2],fd9[2],fd10[2];
	pipe(fd1);
	pipe(fd2);
	pipe(fd3);
	pipe(fd4);
	pipe(fd5);
	pipe(fd6);
	pipe(fd7);
	pipe(fd8);
	pipe(fd9);
	pipe(fd10);
	int cpid=fork();
	if(cpid==0){
		for(var1=0,index=0;index<100;index++)
			var1=var1+Arr[index];
		write(fd1[1], &var1, sizeof(var1));
		close(fd1[1]);
	}	
	else
	{
		int cpid1=fork();
		if(cpid1==0){
			for(var2=0,index=100;index<200;index++)
				var2=var2+Arr[index];
			write(fd2[1], &var2, sizeof(var2));	
			close(fd2[1]);	
		}	
		else
		{	
			int cpid2=fork();
			if(cpid2==0){
				for(var3=0,index=200;index<300;index++)
					var3=var3+Arr[index];
				write(fd3[1], &var3, sizeof(var3));	
				close(fd3[1]);	
			}	
			else
			{	
				int cpid3=fork();
				if(cpid3==0){
					for(var4=0,index=300;index<400;index++)
						var4=var4+Arr[index];
					write(fd4[1], &var4, sizeof(var4));	
					close(fd4[1]);	
				}	
				else
				{	
					int cpid4=fork();
					if(cpid4==0){
						for(var5=0,index=400;index<500;index++)
							var5=var5+Arr[index];
						write(fd5[1], &var5, sizeof(var5));	
						close(fd5[1]);	
					}	
					else
					{	
						int cpid5=fork();
						if(cpid5==0){
							for(var6=0,index=500;index<600;index++)
								var6=var6+Arr[index];
							write(fd6[1], &var6, sizeof(var6));	
							close(fd6[1]);	
						}	
						else
						{	
							int cpid6=fork();
							if(cpid6==0){
								for(var7=0,index=600;index<700;index++)
									var7=var7+Arr[index];
								write(fd7[1], &var7, sizeof(var7));	
								close(fd7[1]);	
							}	
							else
							{	
								int cpid7=fork();
								if(cpid7==0){
									for(var8=0,index=700;index<800;index++)
										var8=var8+Arr[index];
									write(fd8[1], &var8, sizeof(var8));			
									close(fd8[1]);	

								}	
								else
								{	
									int cpid8=fork();
									if(cpid8==0){
										for(var9=0,index=800;index<900;index++)
											var9=var9+Arr[index];
										write(fd9[1], &var9, sizeof(var9));	
										close(fd9[1]);	
									}	
									else
									{	
										int cpid9=fork();
										if(cpid9==0){
											for(var10=0,index=900;index<1000;index++)
												var10=var10+Arr[index];
											write(fd10[1], &var10, sizeof(var10));	
											close(fd10[1]);	
										}	
										else
										{	
											wait(&status);
											wait(&status);
											wait(&status);
											wait(&status);
											wait(&status);
											wait(&status);
											wait(&status);
											wait(&status);
											wait(&status);
											wait(&status);
											
										int var1,var2,var3,var4,var5,var6,var7,var8,var9,var10;
											read(fd1[0], &var1, sizeof(var1));
											read(fd2[0], &var2, sizeof(var2));
											read(fd3[0], &var3, sizeof(var3));
											read(fd4[0], &var4, sizeof(var4));
											read(fd5[0], &var5, sizeof(var5));
											read(fd6[0], &var6, sizeof(var6));
											read(fd7[0], &var7, sizeof(var7));
											read(fd8[0], &var8, sizeof(var8));
											read(fd9[0], &var9, sizeof(var9));
											read(fd10[0], &var10, sizeof(var10));
											sum=var1+var2+var3+var4+var5+var6+var7+var8+var9+var10;
											printf("Sum of 1000 Numbers = %d\n",sum);
											close(fd1[0]);	
											close(fd2[0]);	
											close(fd3[0]);	
											close(fd4[0]);	
											close(fd5[0]);	
											close(fd6[0]);	
											close(fd7[0]);	
											close(fd8[0]);	
											close(fd9[0]);	
											close(fd10[0]);	
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	return 0;
}
