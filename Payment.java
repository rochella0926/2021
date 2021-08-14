
import java.text.SimpleDateFormat;
import java.util.*;
public class Payment {
	
	static int tatal_Income;
	final int FEE_PER_MINUTE=100;
	final int FEE_PER_HOUR=5000;
	long inTime;
	long outTime;
	
int calculateFee(long hour, long minute) {
		
		hour=(outTime-inTime)/3600000;
		minute =(outTime-inTime)/60000-hour;
		long second=((outTime-inTime)/1000-hour-minute);
		
		//30초 이상이면 포함 아니면 무시
		if(second>=30) {
			minute++;
		}
		
		tatal_Income+=hour*FEE_PER_HOUR;
		tatal_Income+=hour*FEE_PER_MINUTE;
	
		
	
		
		return tatal_Income;
		
		
	}
	
	static void printFee() {
		System.out.println("현재 총 수익 : "+tatal_Income+" 원 ");
	}
	
	long setCheckIn() {
		inTime = System.currentTimeMillis();
		SimpleDateFormat inSimpleDateFormat = new SimpleDateFormat("HH:mm:ss");
		SimpleDateFormat format;
		format = new SimpleDateFormat("HH:mm:ss");

	
		System.out.print("입장시간 : "+format.format(inTime));
		

		return inTime;
		
	}
	
	long setCheckOut() {
		outTime = System.currentTimeMillis();
		SimpleDateFormat inSimpleDateFormat = new SimpleDateFormat("HH:mm:ss");
		SimpleDateFormat format;
		format = new SimpleDateFormat("HH:mm:ss");

	
		System.out.println("퇴장시간 : "+format.format(outTime));
		System.out.print("총 이용 시간 : "+format.format(outTime-inTime));
		
		return outTime;
	}
	

}
