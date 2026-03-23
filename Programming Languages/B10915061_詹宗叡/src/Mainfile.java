import java.util.*;
import java.text.SimpleDateFormat;

public class Mainfile
{
	public static void main( String args []) 
	{
		Account[] accountList = new Account[4];
		
		// 設定日期
		SimpleDateFormat dateFirst = new SimpleDateFormat("yyyy-MM-dd");
		Date openDate = null;
		Date lastInterestDate = null;
		Date NewDate = null;
		Date CDAccountCheck12Month = null; //CDAcCompare1
		Date CDAccountCheck13Month = null; //CDAcCompare2
		try {
			openDate = dateFirst.parse("2020-5-06");
			lastInterestDate = dateFirst.parse("2021-2-22");
			NewDate = dateFirst.parse("2021-5-22");
			CDAccountCheck12Month = dateFirst.parse("2021-11-28");
			CDAccountCheck13Month = dateFirst.parse("2021-12-30");
		}
		catch (Exception e)
		{
		    e.printStackTrace();
		}
		// 
		
		// CHECK 同一個名字會出現exception
	    Account a;
	    Date d;
	    double ret;
	    
	    a = new CheckingAccount("John Smith", 1500.0);
	    
	    try {
	    	ret = a.withdraw(100.00);
	    	System.out.println ("Account <" + a.ReturnName() + "> now has $" + ret + " balance\n");
	    } catch (Exception e) {
	       stdExceptionPrinting(e);	
	    }
	    
	    a = new CheckingAccount("John Smith", 1500.0);
	    
	    try { 
	    	ret = a.withdraw(600.00);
	    	System.out.println ("Account <" + a.ReturnName() + "> now has $" + ret + " balance\n");
	    } catch (Exception e) {
	       stdExceptionPrinting(e);	
	    }
		
		// System.out.println (firstInterestDate + " / " + lastInterestDate + "\n"); 

		// 宣告時可以在最後加上opendate，沒有加上的話會自動判斷日期為今天
		accountList[0] = new CheckingAccount("John Smith", 1500.0);
		accountList[1] = new SavingAccount("William Hurt", 1200.0);
		// test 250 fee
		accountList[2] = new CDAccount("Woody Allison", 1000.0);
		accountList[3] = new LoanAccount("Judi Foster", -1500.0);
		
		// CHECK saving account 交易超過三次會扣手續費＄1
		try
		{
			accountList[1].withdraw(100.0, lastInterestDate);
			accountList[1].deposit(100.0, lastInterestDate);
			accountList[1].withdraw(100.0, lastInterestDate);
			accountList[1].deposit(100.0, lastInterestDate);
			accountList[1].withdraw(100.0, NewDate);
			accountList[1].withdraw(100.0, NewDate);
			accountList[1].withdraw(100.0, NewDate);
			accountList[1].deposit(100.0, NewDate);
			for (int count = 0; count < accountList.length; count++) 
			{
				System.out.println ("Account <" + accountList[count].ReturnName() + "> now has $" + accountList[count].computeInterest(lastInterestDate) + " balance\n");
			}
		}
		catch(Exception e) 	
		{
			stdExceptionPrinting(e);
		}
		
		// 少於12個月會被扣250元手續費
		try
		{
			accountList[2].withdraw(100.0, NewDate); 
			System.out.println("Account <" + accountList[2].ReturnName() + "> now has $" + accountList[2].computeInterest(CDAccountCheck12Month) + " balance\n");
		}
		catch(Exception e) 	
		{
			stdExceptionPrinting(e);
		}
		//
		
		// Loan account can't withdraw, so the result should catch an exception
		try
		{
			accountList[3].withdraw(100.0, NewDate); 
			System.out.println("Account <" + accountList[3].ReturnName() + "> now has $" + accountList[3].computeInterest(lastInterestDate) + " balance\n");
		}
		catch(Exception e) 	
		{
			stdExceptionPrinting(e);
		}
		//
		
		// 對比兩個cd account，12個月和13個月的interestdate，在本金相同的情況下結果應為12個月與13個月的利息相同
		Account CDAcCompare1 = new CDAccount("Leung Yan Tung", 1000.0);
		Account CDAcCompare2 = new CDAccount("Yan Tung", 1000.0);
		try{
			System.out.println("Account <" + CDAcCompare1.ReturnName() + "> now has $" + CDAcCompare1.computeInterest(CDAccountCheck12Month ) + " balance\n");
			System.out.println("Account <" + CDAcCompare2.ReturnName() + "> now has $" + CDAcCompare2.computeInterest(CDAccountCheck13Month ) + " balance\n");
		}
		catch(Exception e)
		{
			stdExceptionPrinting(e);
		}
		//


	}
	static void stdExceptionPrinting(Exception e) {
	    System.out.println("EXCEPTION: Banking system throws a " + e.getClass() + " with message: \n\t" + "MESSAGE: " + e.getMessage() + "\n");
	}
}   

       