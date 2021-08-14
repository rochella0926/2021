import java.util.*;
public class Management {
	
	
	int currentNo;
	
	ArrayList<Customer> cst=new ArrayList<Customer>(10);
	SeatManage seatMan=new SeatManage();
	Payment pay=new Payment();
	Scanner sc = new Scanner(System.in);
	
	
	Management(){
		this.currentNo=0;
	}
	
	void setIn() {
		
	
		if(currentNo<10) {//좌석이 남은 경우 
		//이름 입력 
		System.out.println("이름을 입력하세요");
		
		String name=sc.nextLine();
		
		//남은 좌석수 알림
		seatMan.print();
		System.out.println("남은 좌석은 "+(10-currentNo)+"석 입니다. (V:빈자석/C:찬좌석) ");
		System.out.println();
		
		//좌석 번호 입력  
		System.out.println();
		
		int mySeat;
		int x, y;
		System.out.println("좌석을 선택하세요");
		 while(true){
	            
	            try
	            { 
	            	do{
	            		
	        			mySeat = sc.nextInt();
	        			sc.nextLine();
	        			x = (mySeat / 10 )-1;
	        			y = (mySeat % 10) -1;
	        			
	        			if(mySeat/10 >2 || 0>mySeat||mySeat%10 >5  ){//좌석 범위 지정  
	        				System.out.println("다시 입력 하세요");
	        			}
	        		}while(mySeat/10 >2 || 0>mySeat||mySeat%10 >5  );
	        		
	            	 break;
	                 
                }
            catch(InputMismatchException e){
               
                sc.nextLine();
                 System.out.println("사용 가능한 좌석 번호를 입력하세요");
                }
	            
		 }
		
		
		
	
		
		//setSeat 호출 및 저장 
		seatMan.setSeat(x,y);
		
		
			cst.add(new Customer(name));
			cst.get(currentNo).seatID=(x+1)*10+y+1;
			cst.get(currentNo).startTime=pay.setCheckIn();
			

		//currentNo++
		seatMan.setTable[x][y]=true;
		currentNo++;}
		else {
			System.out.println("빈 자리가 없습니다. ");
		}
	

	}
	
	void setOut() {
	
		
		boolean check = false;//이름이 일치하는지 확인 
		int tmp=0;
		int fee=-1;
	
		//이름 입력
		
		System.out.println("이름을 입력하세요");
		String name=sc.nextLine();
		
		
		//이름이 저장된 이름중 일치하는 게 있는지 찾기
		
		
		for(int i=0; i<cst.size();i++) {
			if(cst.get(i).name.equals(name)) {
				tmp=i;
				check=true;
			}
		}
			
		//일치하는 사람이 있는 경우
		try{
		if(check==true) {
			//퇴장시키기 
			Customer outcst=cst.remove(tmp);
			
			System.out.println("당신의 좌석 번호는 "+outcst.seatID+"입니다. ");
			
			//자리 풀어주기
			seatMan.releaseSeat(outcst.seatID/10,outcst.seatID%10);
			
			//퇴장시간안내
			outcst.endTime=pay.setCheckOut();
			
			
			//요금 정산
			fee=pay.calculateFee(outcst.startTime, outcst.endTime);
			if(fee==-1)
				System.out.println("관리자에게 문의하세요.  ");
			else
				System.out.println("총 요금은 "+fee+"원 입니다. ");
			
			//currentNo
			currentNo--;
			
			
			
		}else
			System.out.println("일치하는 이름이 없습니다. 처음부터 다시 시작하세요.");}
		
		catch(NullPointerException e){
			System.out.println("일치하는 이름이 없습니다. 처음부터 다시 시작하세요.");
		}
		
	

	}
	
	
	 void admin(){ //관리자모드

		System.out.println("1. 현재 좌석 상태 보기");
		System.out.println("2. 전체 좌석 리셋 하기");
		System.out.println("3. 손님 현황 보기");
		System.out.println("4. 총 수입 확인 하기");
		
		int system=0;

	
		
        while(true){
            
            try{
                 
            	System.out.println("-->");
                 
              //  int system =Integer.parseInt(sc.nextLine());//입력 오류를 방지하기 위해서(개행문자 때문에 발생)
            	system=sc.nextInt();
            	sc.nextLine();//입력 오류를 방지하기 위해서(개행문자 때문에 발생)
            	
                switch(system){
                case 1:
			    	 System.out.println("[현재 좌석 상태]");
			    	 seatMan.print();
			    	 System.out.print("찬 좌석 :"+currentNo+"\t");
			    	 System.out.println("남은 좌석 : "+(10-currentNo));
			    	 break;

			     case 2:
			    	 seatMan.clear();
			    	 System.out.println("모든 좌석이 해제되었습니다.");
			    	 break;
			     
			     
			     case 3: 
			    	 System.out.print("좌석번호 \t");
			    	 System.out.println("이름");
			    	 System.out.println("------------------------");
			    	 for(int i=0; i<cst.size();i++) {
			    	 System.out.print(cst.get(i).seatID+"\t");
			    	 System.out.println(cst.get(i).name);}
			    	 break;
			    	 
			    case 4:
			    	Payment.printFee();
				    break;

                
                default : System.out.println("1~4 중 하나를 입력하세요");continue;}    
                 
                break;
                 
                }
            catch(InputMismatchException e){
               
                sc.nextLine();
                 System.out.println("1~4 중 하나를 입력하세요");
                }
             
        }

				    
				     
				
				    	 
	    
				    
	 
				     

				     
				 
	}
		
}
