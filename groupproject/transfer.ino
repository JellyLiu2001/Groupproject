//Designed by Jelly Jinzhe Liu ab20328
void transfer() {//Limit the angle of the gyroscope to prevent damage due to excessive angles
  if (c >= 160) {
    c = 160;
  }
  if (d >= 160) {
    d = 160;
  }
  if (c <= 20) {
    c = 20;
  }
  if (d <= 20) {
    d = 20;
  }
}