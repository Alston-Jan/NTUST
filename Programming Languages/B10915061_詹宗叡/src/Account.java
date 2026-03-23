import java.util.*;


class BankingException extends Exception
{
    BankingException () { super(); }
    BankingException (String s) { super(s); }
} 

interface BasicAccount 
{
}

interface WithdrawableAccount extends BasicAccount 
{
    double withdraw(double amount) throws BankingException;	
}

interface DepositableAccount extends BasicAccount 
{
    double deposit(double amount) throws BankingException;	
}

interface InterestableAccount extends BasicAccount
{
    double computeInterest() throws BankingException;	
}

interface FullFunctionalAccount extends WithdrawableAccount,
                                        DepositableAccount,
                                        InterestableAccount {
}


public abstract class Account
{
	protected String name;
    protected double balance;
    protected double interestRate;
    protected Date openDate;
    protected Date lastInterestDate;
    protected Date lastTransactionDate;
    
    abstract double deposit(double amount, Date depositDate) throws BankingException;
    
    public double deposit(double amount) throws BankingException
    {
    	Date depositDate = new Date();
        return(deposit(amount, depositDate));
    } 
    
    abstract double withdraw(double amount, Date withdrawDate) throws BankingException;
    
    public double withdraw(double amount) throws BankingException 
    {
        Date withdrawDate = new Date();
        return(withdraw(amount, withdrawDate));
    }
    
    public String ReturnName()  // return the customer's name
    {
    	return(name);	
    }	
    
    public double ReturnBalance() // return the balance of the account
    {
        return(balance);
    }
    
    abstract double computeInterest(Date interestDate) throws BankingException;
    
    public double computeInterest() throws BankingException
    {
        Date interestDate = new Date();
        return(computeInterest(interestDate));
    }

}
/* * * * * * * * * * * * * *
 *     Checking Account    *
 *      daily interest     *
 * 		提款沒有手續費		   *
 *     但存款不能少於1000    *
 * * * * * * * * * * * * * */

class CheckingAccount extends Account implements FullFunctionalAccount { //提款沒有手續費 但不能少於1000

    CheckingAccount(String s, double firstDeposit) 
    {
        name = s;
        balance = firstDeposit;
        interestRate = 0.12;
        openDate = new Date(); // 現在時間
        lastInterestDate = openDate;	// 最後算息日期為今日       
    }
    
    CheckingAccount(String s, double firstDeposit, Date firstDate) 
    {
        name = s;
        balance = firstDeposit;
        interestRate = 0.12;
        openDate = firstDate;
        lastInterestDate = openDate;

    }	
    
    public double withdraw(double amount, Date withdrawDate) throws BankingException 
    {
    	if (withdrawDate.before(openDate)) 
        {
            throw new BankingException ("Invalid date to withdraw money from account name" + name);                            	
        }
    // minimum balance is 1000, raise exception if violated
        if ((balance  - amount) < 1000) 
        {
            throw new BankingException ("Underfraft from checking account name:" + name);
        } 

        balance -= amount;	
		System.out.println("<Withdraw> " + name + ", You has $" + balance + " balance.\n");
        return(balance); 	
                                              	
    }
    
    public double deposit(double amount, Date depositDate) throws BankingException 
    {
    	if (depositDate.before(openDate)) 
        {
            throw new BankingException ("Invalid date to deposit to account name" + name);                            	
        }
        balance += amount;	// 
		System.out.println("<Deposit> " + name + ", You has $" + balance + " balance.\n");
        return(balance); 	                                              	
    }
    
    public double computeInterest (Date interestDate) throws BankingException 
    {
        if (interestDate.before(lastInterestDate)) 
        {
            throw new BankingException ("Invalid date to compute interest for account name" + name);                            	
        }
        
        int numberOfDays = (int) ((interestDate.getTime() - lastInterestDate.getTime()) / 86400000.0); // calculate days
        System.out.println("Number of days since last interest is " + numberOfDays);
        double interestEarned = (double) numberOfDays / 365.0 * interestRate * balance;
        System.out.println("Interest earned is " + interestEarned); 
        lastInterestDate = interestDate;
        balance += interestEarned;
        return(balance);                            
    }  	
}       

/* * * * * * * * * * * * * *
 *     Saving Account      *
 *    monthly interest     *
 * 	  前三次交易沒有手續費	   *
 *     超過每次一元手續費     *
 * * * * * * * * * * * * * */

class SavingAccount extends Account implements FullFunctionalAccount { // monthly interest（不到一個月不算）, 提款存款都有手續費 每月前三次免費
    protected List<Integer> totalTransactionTimes = new ArrayList<Integer>();
    protected boolean firstTime;
    
	SavingAccount(String s, double firstDeposit) 
    {
        name = s;
        balance = firstDeposit;
        interestRate = 0.12;
        openDate = new Date();
        lastInterestDate = openDate;
        lastTransactionDate = openDate;
        firstTime = true;
        totalTransactionTimes.add(0);
    }
    
	SavingAccount(String s, double firstDeposit, Date firstDate) 
    {
        name = s;
        balance = firstDeposit;
        interestRate = 0.12;
        openDate = firstDate;
        lastInterestDate = openDate;	
        lastTransactionDate = openDate;
        firstTime = true;
        totalTransactionTimes.add(0);
    }	
	
	public int ReturnCalculatedMonths(Date d1, Date d2) throws BankingException// 計算月數
	{
		int numberOfMonths = (int) (((d1.getTime() - d2.getTime()) / 86400000.0) / 30);
		return(numberOfMonths);
	}
	
	public int totalTransactionTimes(List<Integer> totalTtotalTransactionTimes, Date transactionDate, int currentMonth) throws BankingException
	{
		// 不用加expection，因為在deposit和withdraw如果日期有錯就會丟出expection，不會跑到這邊

		int transactionTimes = 0;
		int numberOfMonthsInAndLast = ReturnCalculatedMonths(transactionDate, lastTransactionDate);
    	//System.out.println(numberOfMonthsInAndLast); 
		int numberOfMonthsOpenAndLast = ReturnCalculatedMonths(transactionDate, openDate);
    	//System.out.println("transactionDate " + transactionDate + " lastTransactionDate " + lastTransactionDate + " " + numberOfMonthsOpenAndLast); 
		if(transactionDate.after(lastTransactionDate))  
		{
			if(firstTime)
			{
				firstTime = false;
				for(int i = 0; i < numberOfMonthsOpenAndLast ; i++)
				{				
					totalTransactionTimes.add(0);
				}
			}
			else
			{
				if(numberOfMonthsInAndLast != 0)
				{
					for(int i = 0; i < numberOfMonthsInAndLast; i++)
					{				
						totalTransactionTimes.add(0);
					}
				}
			}
		}
		
    	//System.out.println("size" + totalT.size()); // 檢查dynamic totalT 的size
		transactionTimes = (int)totalTransactionTimes.get(currentMonth - 1);
		return transactionTimes;
	}
	
	
    public double withdraw(double amount, Date withdrawDate) throws BankingException 
    {
    	if (withdrawDate.before(openDate))  //如果提款時間比開戶時間早則輸入日期有誤
        {
            throw new BankingException ("Invalid date to withdraw money from account name" + name);                            	
        }
    	
    	int currentMonth = ReturnCalculatedMonths(withdrawDate, openDate);
    	int num = totalTransactionTimes(totalTransactionTimes, withdrawDate, currentMonth);
    	totalTransactionTimes.set((currentMonth - 1), num + 1 );
    	int getNum = totalTransactionTimes.get(currentMonth - 1);
    	
    	if(getNum > 3) // getnum是該月的交易次數，若超過3次每次要給1元手續費
    	{
    		if(balance - (amount + 1) < 0)
    		{
    			throw new BankingException ("Invalid amount to withdram money from account name " + name);
    		}
    		balance -= (amount + 1);
    	}
    	else
    	{
    		if(balance - amount < 0)
    		{
    			throw new BankingException ("Invalid amount to withdram money from account name " + name);
    		}
    		balance -= amount;
    	}
    	

    	/*for(int i = 0; i < currentMonth ; i++)
    	{
    		getNum = totalT.get(i);
    		//System.out.println(getNum); 
    	}*/
    	lastTransactionDate = withdrawDate; // 設定最後交易日期為withdrawDate
		System.out.println("<Withdraw> " + name + ", You has $" + balance + " balance.\n");
    	return(balance); 	                                   	
    }
    
    public double deposit(double amount, Date depositDate) throws BankingException 
    {
    	if (depositDate.before(openDate)) 
        {
            throw new BankingException ("Invalid date to deposit to account name" + name);                            	
        }
    	
    	int currentMonth = ReturnCalculatedMonths(depositDate, openDate);
    	int num = totalTransactionTimes(totalTransactionTimes, depositDate, currentMonth);
    	totalTransactionTimes.set((currentMonth - 1), num + 1 );
    	int getNum = totalTransactionTimes.get(currentMonth - 1);
    	
    	if(getNum > 3)
    	{
    		balance += (amount - 1);
    	}
    	else
    		balance += amount;

    	/*for(int i = 0; i < currentMonth ; i++)
    	{
    		getNum = totalT.get(i);
    	}*/
    	lastTransactionDate = depositDate;
		System.out.println("<Deposit> " + name + ", You has $" + balance + " balance.\n");
    	return(balance); 	                                   	
    }
    
    public double computeInterest (Date interestDate) throws BankingException 
    {
        if (interestDate.before(lastInterestDate)) 
        {
            throw new BankingException ("Invalid date to compute interest for account name" + name);                            	
        }
        
        int numberOfMonths = ReturnCalculatedMonths(interestDate, lastInterestDate);
        System.out.println("Number of months since last interest is " + numberOfMonths);
        double interestEarned = (double) numberOfMonths / 12.0 * interestRate * balance;
        System.out.println("Interest earned is " + interestEarned); 
        
        lastInterestDate = interestDate; //更新最後計息日
        balance += interestEarned;
        return(balance);  
    }  	
}

/* * * * * * * * * * * * * *
 *     	 CD Account        *
 *    monthly interest     *
 * 	  12個月內不能提款存款	   *
 *     提款一次手續費250     *
 * * * * * * * * * * * * * */

class CDAccount extends Account implements FullFunctionalAccount 
{
	protected double duration;
	
	CDAccount(String s, double firstDeposit) 
    {
        name = s;
        balance = firstDeposit;
        duration = 12;
        interestRate = 0.12;
        openDate = new Date();
        lastInterestDate = openDate;	
    }
	
	CDAccount(String s, double firstDeposit, double durationMonths) 
    {
        name = s;
        balance = firstDeposit;
        duration = durationMonths;
        interestRate = 0.12;
        openDate = new Date();
        lastInterestDate = openDate;	
    }	
    
	CDAccount(String s, double firstDeposit, Date firstDate, double durationMonths) 
    {
        name = s;
        balance = firstDeposit;
        duration = durationMonths;
        interestRate = 0.12;
        openDate = firstDate;
        lastInterestDate = openDate;	
    }	
	
	public int ReturnCalculatedMonths(Date d1, Date d2) throws BankingException
	{
		int numberOfMonths = (int) (((d1.getTime() - d2.getTime()) / 86400000.0) / 30);
		return(numberOfMonths);
	}
	
	public double withdraw(double amount, Date withdrawDate) throws BankingException 
    {
		if (withdrawDate.before(openDate)) 
        {
            throw new BankingException ("Invalid date to withdraw money from account name" + name);                            	
        }
		
		if(ReturnCalculatedMonths(withdrawDate, openDate) < duration) // 從開帳號當天到你要提款當天如果沒有滿12個月，則會需要250手續費
		{
    		if(balance - (amount + 250) < 0) // 提款加上手續費後超過戶口的存款
    		{
    			throw new BankingException ("Invalid amount to withdram money from account name " + name);
    		}
			System.out.println("Since your account has opened less than 12months, to withdraw from your account you need to pay 250 for fee"); 
			balance -= (amount + 250);
		}
        else 
        {
        	if(balance - amount< 0) // 提款加上手續費後超過戶口的存款
    		{
    			throw new BankingException ("Invalid amount to withdram money from account name " + name);
    		}
            balance -= amount;		
        }         
		System.out.println("<Withdraw> " + name + ", You has $" + balance + " balance.\n");
        return(balance); 
    }
	
	public double deposit(double amount, Date depositDate) throws BankingException 
	{
		if (depositDate.before(openDate)) 
        {
            throw new BankingException ("Invalid date to deposit to account name" + name);                            	
        }
		
		if(ReturnCalculatedMonths(depositDate, openDate) < duration) //還沒滿duration不能提款
		{
			 throw new BankingException (name + "You are not allow to deposit before your duration.\n");  
		}
        else 
        {
            balance += amount;		
        }         
		System.out.println("<Deposit> " + name + ", You has $" + balance + " balance.\n");
        return(balance); 
    }
    
    public double computeInterest (Date interestDate) throws BankingException 
    {
        if (interestDate.before(lastInterestDate)) 
        {
            throw new BankingException ("Invalid date to compute interest for account name" + name);                            	
        }
        double interestEarned;
        int numberOfMonthsOpenToInter = ReturnCalculatedMonths(interestDate, openDate);
        int numberOfMonths = ReturnCalculatedMonths(interestDate, lastInterestDate);
        System.out.println("Number of months since last interest is " + numberOfMonths);

        if(numberOfMonthsOpenToInter < duration ) // 開戶至計息日不足duration
        {
            interestEarned = (double) numberOfMonths / 12.0 * interestRate * balance;
            System.out.println("Interest earned is " + interestEarned); 
            balance += interestEarned;
        }
        else
        {
        	interestEarned = (double) duration / 12.0 * interestRate * balance;
            System.out.println("Interest earned is " + interestEarned); 
            balance += interestEarned;
        }
        lastInterestDate = interestDate;
        return(balance);                            
    }  	
}

class LoanAccount extends Account implements FullFunctionalAccount { // like saving account

	LoanAccount(String s, double firstDeposit) 
    {
        name = s;
        balance = firstDeposit;
        interestRate = 0.12;
        openDate = new Date();
        lastInterestDate = openDate;	
    }
    
	LoanAccount(String s, double firstDeposit, Date firstDate) 
    {
        name = s;
        balance = firstDeposit;
        interestRate = 0.12;
        openDate = firstDate;
        lastInterestDate = openDate;	
    }	
	
	public int ReturnCalculatedMonths(Date interestDate) throws BankingException
	{
		int numberOfMonths = (int) (((interestDate.getTime() - lastInterestDate.getTime()) / 86400000.0) / 30);
		return(numberOfMonths);
	}
	
	public double withdraw(double amount, Date withdrawDate) throws BankingException 
    {
		if(balance - amount <= 0)
		{
			throw new BankingException ("Your balance is less than 0, you can't reduce amount from your account name <" + name + ">");     
		}
        else 
        {
            balance -= amount;		
        }         
		System.out.println("<Withdraw> " + name + ", You has $" + balance + " balance.\n");
		return(balance); 
    }
	
	public double deposit(double amount, Date depositDate) throws BankingException 
	{
		if (depositDate.before(openDate)) 
        {
            throw new BankingException ("Invalid date to deposit to account name" + name);                            	
        }
		
        balance += amount;		
        System.out.println("<Deposit> " + name + ", You has $" + balance + " balance.\n");
        return(balance); 
    }
	
    public double computeInterest (Date interestDate) throws BankingException 
    {
        if (interestDate.before(lastInterestDate)) 
        {
            throw new BankingException ("Invalid date to compute interest for account name" + name);                            	
        }
        double interestEarned;
        int numberOfMonths = ReturnCalculatedMonths(interestDate);
        System.out.println("Number of months since last interest is " + numberOfMonths);
        interestEarned = (double) numberOfMonths / 12.0 * interestRate * balance; // 月息
        System.out.println("Interest earned is " + interestEarned); 
        lastInterestDate = interestDate;
        balance += interestEarned;
        return(balance);                            
    }  	
}
