public class CellState{
	public static int getCellState(int row, int col, int[][] current){
		int liveCount = 0;
		int lastCellIndex = N -1 ;

		if(row > 0 && col > 0){
			liveCount += current[row-1][col+ 1];
		}

		if(row > 0){
			liveCount += current[row-1][col];
			if( col < lastCellIndex){
				liveCount += current[row]
			}
		}
	}
}