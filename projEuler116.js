/*
    Stephen Penkov, CISP440: ProjectEuelr 116, 2/1/17
    Purpose: This javascript program counts the number of ways
    a colored tile of size 2-4, that can be placed in a row of 50 empty tiles.
*/


function factorial(n){
  //function to calculate n factorial.
  if(n == 0 || n == 1)
    return 1;
  else {
    return n * factorial(n - 1);
  }
}

function find_solutions(n,k){
  //This functions finds the solution using the combination formula, n!/k!(n-k)! ,
  //where n = number of colored blocks + black tiles, and
  //k = the number of black tiles remaining.
  var num = factorial(n);
  var denom = (factorial(k) * factorial(n - k));
  var solutions = num / denom;
  return solutions;

}

function max_blocks(tile_size, block_size){
  //This function returns the maximum number of blocks
  //of size 2-4, that can fit into a row of 50 tiles.
  if(block_size > tile_size)
      return 0;
  if(tile_size % block_size == 0)
      return (tile_size / block_size);
  else return(max_blocks(tile_size - 1, block_size));
}

//Variable declarations
var total_solutions = 0;
var n = 0;
var k = 0;
var max_color_tiles_allowed = 0;

function run(_size){
//This function runs the program. The outer loop feeds the block size for each
//colored block, and the inner loop adds more colored blocks per iteration, never
//exceeding the maximum blocks allowed in a row of 50 tiles. Once n and k are found
//the solutions are found using the find_solutions() function.
  console.time("CPU_TIME");

  var total_solutions = 0;
  for(var i = 2; i <= 4; ++i){
      max_color_tiles_allowed = max_blocks(_size, i);
      for(var j = 1; j <= max_color_tiles_allowed; ++j){
        n = (j + _size) - (j*i);
        k = _size - (i*j);
        total_solutions += find_solutions(n, k);
      }
  }
  var cpu_time = console.timeEnd("CPU_TIME");
  return total_solutions;
}
console.log("| Stephen Penkov | CISP440 | Project Euler 116| 2/1/17 |\n");
console.log("Total solutions for a row of 5 tiles: " + run(5) + ".\n");
console.log("Total solutions for a row of 50 tiles: " + run(50) + ".\n");
