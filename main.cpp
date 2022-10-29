#define WIN32_LEAN_AND_MEAN
#include <iostream>
#include <stdio.h>
#include <windows.h>

double homeX;
double homeY;
int stepX = 16;
int stepY = 16;

void mouseMove(int x, int y) {
  double fScreenWidth = ::GetSystemMetrics(SM_CXSCREEN) - 1;
  double fScreenHeight = ::GetSystemMetrics(SM_CYSCREEN) - 1;
  double fx = x * (65535.0f / fScreenWidth);
  double fy = y * (65535.0f / fScreenHeight);
  homeX = fScreenWidth / 2;
  homeY = fScreenHeight / 2;

  INPUT Input = {0};
  Input.type = INPUT_MOUSE;
  Input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE;
  Input.mi.dx = fx;
  Input.mi.dy = fy;
  ::SendInput(1, &Input, sizeof(INPUT));
  Sleep(2);
}

void mouseDown() {
  INPUT Input = {0};
  Input.type = INPUT_MOUSE;
  Input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
  ::SendInput(1, &Input, sizeof(INPUT));
}

void mouseUp() {
  INPUT Input = {0};
  Input.type = INPUT_MOUSE;
  Input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
  ::SendInput(1, &Input, sizeof(INPUT));
}

void downArrow() {
  mouseMove(homeX - stepX * 2, homeY - stepY);
  mouseDown();
  mouseMove(homeX - stepX, homeY);
  mouseMove(homeX, homeY + stepY);
  mouseMove(homeX + stepX, homeY);
  mouseMove(homeX + stepX * 2, homeY - stepY);
  mouseUp();
}

void upArrow() {
  mouseMove(homeX - stepX * 2, homeY + stepY);
  mouseDown();
  mouseMove(homeX - stepX, homeY);
  mouseMove(homeX, homeY - stepY);
  mouseMove(homeX + stepX, homeY);
  mouseMove(homeX + stepX * 2, homeY + stepY);
  mouseUp();
}

void flatLine() {
  mouseMove(homeX - stepX * 2, homeY);
  mouseDown();
  mouseMove(homeX - stepX, homeY);
  mouseMove(homeX + stepX, homeY);
  mouseMove(homeX + stepX * 2, homeY);
  mouseUp();
}

void vertLine() {
  mouseMove(homeX, homeY - stepY * 2);
  mouseDown();
  mouseMove(homeX, homeY - stepY);
  mouseMove(homeX, homeY + stepY);
  mouseMove(homeX, homeY + stepY * 2);
  mouseUp();
}

int main(int argc, char *argv[]) {
  std::cout << "nutz" << std::endl;
  while (true) {
    if (GetKeyState('P') & 0x8000)
      exit(0);
    if (GetKeyState('U') & 0x8000) {
      vertLine();
    }
    if (GetKeyState('J') & 0x8000) {
      flatLine();
    }
    if (GetKeyState('I') & 0x8000) {
      upArrow();
    }
    if (GetKeyState('K') & 0x8000) {
      downArrow();
    }
    if (GetKeyState('O') & 0x8000) {
      vertLine();
      flatLine();
      upArrow();
      downArrow();
    }
    Sleep(5);
  }
}