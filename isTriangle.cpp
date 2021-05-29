namespace Triangle;
{
  bool isTriangle(int side_a, int side_b, int side_c)
  {
  if(side_a < 1 || side_b < 1 || side_c < 1){
    return false;
  }
	if (
		side_a + side_b > side_c &&
		side_c + side_b > side_a &&
		side_a + side_c > side_b
		)
		return true;
	else
		return false;
}
};
