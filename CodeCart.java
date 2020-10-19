/*
The program here generated for a online shopping cart
It sells only shoe and shirt
Sales Manager gets to decide the cost and number of the products

Add adds the required product to the cart
remove to remove the particular item
dcr to decrement the particular item
incr to increment the amount 

SM - sales manager
S - shopper
CMD SM ADD/REMOVE/GET-QTY/SET-COST/INCR/DCR SHIRT/SHOE
CMD S ADD/REMOVE/INCR/DCR/GET_ORDER_AMOUNT SHIRT/SHOE
*/

import java.lang.*;
import java.io.*;
import java.util.*;
class CodeCart	
{
	public static void main(String[] args)
	{
		int t;
		Scanner sca1 = new Scanner(System.in);
		t = sca1.nextInt();
		Scanner sca2 = new Scanner(System.in);
		String strA = sca2.nextLine();
		int e,d;
		Shopper s = new Shopper();
		SalesManager sm = new SalesManager();
		for(int i=0;i<t;i++)
		{
			int shirtq=0,shoeq=0;
			while(strA.equals("END")==false)
			{
				String[] str = strA.split(" "); 
				if(str[0].equals("CMD")&& str[1].equals("SM"))
				{
					sm.creates(str);
				}
				else if(str[0].equals("CMD")&& str[1].equals("S"))
				{
						s.shops(str,sm);
				}
				strA = sca2.nextLine();
			}
		}
	}
}
class SalesManager
{
	float shirtc,shoec;
	 int stringToInteger(String a)
	{
		try
		{
			int d = Integer.parseInt(a);
			return d;
		}
	    catch (NumberFormatException nfe)
		{
		return -1;
		}
	}
	 float stringToFloat(String a)
	{
		try
		{
			int d = Integer.parseInt(a);
			return d;
		}
	    catch (NumberFormatException nfe)
		{
		return -1;
		}
	}
	void creates(String[] str)
	{
		int shirtq=0,shoeq=0;
		shirtc =0;shoec=0;
		int d;
		CodeCart c = new CodeCart();
					if(str[2].equals("ADD"))
					{
						if(str[3].equals("SHIRT"))
						{
							d = stringToInteger(str[4]);
							shirtq = shirtq+d;
							 System.out.println(d);
						}
						else if(str[3].equals("SHOE"))
						{
							d = stringToInteger(str[4]);
							shoeq = shoeq+d;
							 System.out.println(d);
						}
						else
						System.out.println("-1");
					}
					else if(str[2].equals("REMOVE"))
					{
						if(str[3].equals("SHIRT"))
						{
							System.out.println("1");
								shirtq=-1;
						}
						else if(str[3].equals("SHOE"))
						{
							System.out.println("1");
							shoeq=-1;
						}
						else
						System.out.println("-1");
					}
					else if(str[2].equals("GET_QTY"))
					{
							if(str[3].equals("SHIRT") && shirtq!=-1)
							{
								System.out.println(shirtq);
							}
							else if(str[3].equals("SHOE") && shoeq!=-1)
							{
								System.out.println(shoeq);
							}
							else 
							System.out.println("0");
					}
					else if(str[2].equals("INCR"))
					{
						 d = stringToInteger(str[4]);
						if(str[3].equals("SHIRT") && shirtq!=-1 && d!=-1)
						{
							shirtq = shirtq+d;
							System.out.println(d);
						}
						else if(str[3].equals("SHOE") && shoeq!=-1  && d!=-1)
						{
							shoeq = shoeq+d;
							System.out.println(d);
						}
						else
							System.out.println("-1");
					}
					else if(str[2].equals("DCR"))
					{
						 d = 	stringToInteger(str[4]);
						if(str[3].equals("SHIRT") && d!=-1 && shirtq!=-1 )
						{
							shirtq = shirtq-d;
							System.out.println(d);
						}
						else if(str[3].equals("SHOE") && d!=-1 && shoeq!=-1)
						{
							shoeq = shoeq-d;
							System.out.println(d);
						}
						else
							System.out.println("-1");
					}
					else if(str[2].equals("SET_COST"))
					{
						//cost decimal so dont call the function
						if(str[3].equals("SHIRT"))
						{
							shirtc = stringToFloat(str[4]);
							System.out.println(shirtc);
						}
						else if(str[3].equals("SHOE"))
						{
							shoec = stringToFloat(str[4]);
							System.out.println(shoec);
						}
						else
							System.out.println("-1");
					}
	}
}
class Shopper
{
	void shops(String[] str, SalesManager sm)
	{
		int shoecart=0,shirtcart=0;
		int e;
		CodeCart c = new CodeCart();
					if(str[2].equals("ADD"))
					{
						if(str[3].equals("SHIRT"))
						{
							e = sm.stringToInteger(str[4]);
							shirtcart = shirtcart+e;
							 System.out.println(e);
						}
						else if(str[3].equals("SHOE"))
						{
								e = sm.stringToInteger(str[4]);
							shoecart = shoecart+e;
							 System.out.println(e);
						}
						else
						System.out.println("-1");
					}
					else if(str[2].equals("REMOVE"))
					{
						if(str[3].equals("SHIRT"))
						{
							System.out.println("1");
								shirtcart=-1;
						}
						else if(str[3].equals("SHOE"))
						{
							System.out.println("1");
							shoecart=-1;
						}
						System.out.println("-1");
					}
					else if(str[2].equals("INCR"))
					{
						e = sm.stringToInteger(str[4]);
						if(str[3].equals("SHIRT") && shirtcart!=-1 && e!=-1)
						{
							shirtcart = shirtcart+e;
							System.out.println(e);
						}
						else if(str[3].equals("SHOE") && shoecart!=-1  && e!=-1)
						{
							shoecart = shoecart+e;
							System.out.println(e);
						}
						else
							System.out.println("-1");
					}
					else if(str[2].equals("DCR"))
					{
						e = sm.stringToInteger(str[4]);
						if(str[3].equals("SHIRT") && e!=-1 && shirtcart!=-1 )
						{
							shirtcart = shirtcart-e;
							System.out.println(e);
						}
						else if(str[3].equals("SHOE") && e!=-1 && shoecart!=-1)
						{
							shoecart = shoecart-e;
							System.out.println(e);
						}
						else
							System.out.println("-1");
					}
					else if(str[2].equals("GET_ORDER_AMOUNT"))
					{
						float total_price=0;
						if(shirtcart!=-1)
							total_price = total_price+(shirtcart*sm.shirtc);
						if(shoecart!=-1)
							total_price = total_price+(shoecart*sm.shoec);
						System.out.println(total_price);
					}
	
	}
}	
				