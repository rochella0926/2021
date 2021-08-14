import java.util.*;

public class Menu {
	public static void main(String[] agrs) {
		Management menu=new Management();
		
int end=1;//프로그램 종료를 위한 변수 
		while(end==1) {
		System.out.println("");
		System.out.println("-------------------------------");
		System.out.println("");
		System.out.println("~~LaLaLa StudyRoom~~");
		System.out.println("1.입장");
		System.out.println("2.퇴장");
		System.out.println("3.관리자");
		System.out.println("4.종료");
		
		

	 	 
                	 
		 Scanner sc =new Scanner(System.in);
	        
	         
	        while(true){
	            
	            try{
	                 
	            	System.out.println("-->");
	                 
	              //  int system =Integer.parseInt(sc.nextLine());//입력 오류를 방지하기 위해서(개행문자 때문에 발생)
	            	int system=sc.nextInt();
	            	sc.nextLine();//입력 오류를 방지하기 위해서(개행문자 때문에 발생)
	            	
	                switch(system){
	           	 

	                case 1 :menu.setIn();break;

	                case 2 :menu.setOut();break;

	                case 3 :menu.admin();break;

	                case 4 :System.out.println("시스템을 종료합니다.");end=0;
	                
	                default : System.out.println("1~4 중 하나를 입력하세요");continue;}    
	                 
	                break;
	                 
	                }
	            catch(InputMismatchException e){
	               
	                sc.nextLine();
	                 System.out.println("1~4 중 하나를 입력하세요");
	                }
	             
	        }


                    
                
		
	

}
		//sc.close();
	}
}
	


