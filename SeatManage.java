import java.util.*;
public class SeatManage {
	
	boolean[][] setTable=new boolean[2][5];
	

	public boolean SeatManage() {
		for(int i=0;i<2;i++){

			for(int j=0;j<5;j++){
				if(setTable[i][j]==true )
					return true;
				else return false;

		}
}
		return false;
		
	}
	void clear(){//초기화

		for(int i=0;i<2;i++){

			for(int j=0;j<5;j++){

				setTable[i][j]=false; 

			}

		}

	}

	void print() { // 좌석조회 및 출력
		// 조회 - 조회는 모든 좌석을 출력한다.
		
		for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 5; j++) {
            	if(setTable[i][j]==true)
            	   System.out.print("C"+"["+(i+1)+(j+1) + "] ");
            	else
            		System.out.print("V"+"["+(i+1)+(j+1) + "] ");
            }
            System.out.println(" ");
        }
	}

	
	
	void setSeat(int x,int y) {
		

                
		
            	if(setTable[x][y]==true)
            		System.out.println("사용 중 입니다. 처음부터 다시 시작하세요. ");
            		//사용 중인
            	else {
            		setTable[x][y]=true;
            		System.out.println("선택 되었습니다. ");
            		
        
		}
		
	}
	
	void releaseSeat(int x, int y) {
		
		for (x= 0; x < 2; x++) {
            for (y = 0; y < 5; y++) {
            	if(setTable[x][y]==true)
            		setTable[x][y]=false; 
            		
            	
            }
		}
	}
}
	