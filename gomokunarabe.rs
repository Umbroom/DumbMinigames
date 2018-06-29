const WIDTH: usize = 5;


fn read<T: std::str::FromStr>() -> Vec<T> {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).ok();
    s.trim().split_whitespace()
        .map(|e| e.parse().ok().unwrap()).collect()
}


fn main() {
	let number = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9'];
	let mut field = [[' '; WIDTH + 4]; WIDTH + 4];
	let mut turn = 'x';
	let mut next_move: Vec<usize>;
	let mut decision = [false; 4];

	//add scales
	for i in 1..(WIDTH + 1){
		field[1][i+1] = number[i];
		field[i+1][1] = number[i];
	}

	//show the field
	for y in 1..(WIDTH + 2){
		for x in 1..(WIDTH + 2){
			print!("{} ", field[y][x]);
		}
		println!();
	}
	
	//main loop
	'main_loop: for _ in 0..(WIDTH*WIDTH) {

		//input
		loop{
			next_move = read();
			if next_move.len() == 2 {
				if 1 <= next_move[0] && next_move[0] <= WIDTH && 1 <= next_move[1] && next_move[1] <= WIDTH {
					if field[next_move[1]+1][next_move[0]+1] == ' ' {
						break;
					}
				}
			}
		}
		field[next_move[1]+1][next_move[0]+1] = turn;
		
		//show the field
		for y in 1..(WIDTH + 2){
			for x in 1..(WIDTH + 2){
				print!("{} ", field[y][x]);
			}
			println!();
		}

		//judge
		for y in 2..(WIDTH + 2){
			for x in 2..(WIDTH + 2){
				decision[0] = field[y - 2][x] == turn && field[y - 1][x] == turn && field[y][x] == turn && field[y + 1][x] == turn && field[y + 2][x] == turn;
				decision[1] = field[y][x - 2] == turn && field[y][x - 1] == turn && field[y][x] == turn && field[y][x + 1] == turn && field[y][x + 2] == turn;
				decision[2] = field[y - 2][x - 2] == turn && field[y - 1][x - 1] == turn && field[y][x] == turn && field[y + 1][x + 1] == turn && field[y + 2][x + 2] == turn;
				decision[3] = field[y + 2][x - 2] == turn && field[y + 1][x - 1] == turn && field[y][x] == turn && field[y - 1][x + 1] == turn && field[y - 2][x + 2] == turn;
				
				for d in decision.iter(){
					if d == &true {
						println!("{} is winner.", turn);
						break 'main_loop;
					}
				}
			}
		}

		//relieve
		if turn == 'o' {
			turn = 'x';
		}else{
			turn = 'o';
		}
	}
}