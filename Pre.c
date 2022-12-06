            {

                output(stack[top]);

                POP();

            }

            POP();

        }

        else if(ISP(stack[top])>ICP(item))

        {

            while(ISP(stack[top])>ICP(item))

            {

                output(stack[top]);

                POP();

            }

                PUSH(item);

        }

        else if(ISP(stack[top])<ICP(item))

        {

            PUSH(item);

        }

        else 

            PUSH(item);

        j++;

    }

    for(int k=0;k<j;k++)

    {

        printf("%c",prefix[j-k-1]);

    }

}

