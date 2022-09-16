#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int n;

// Function to binary search (lower bound) within beginning and variable end of
// array
int bin_search(int list[], int query_index) {
  int low = 0;
  int high = query_index;
  while (low < high) {
    int mid = (low + high) / 2;
    if (list[mid] < list[query_index]) {
      low = mid + 1;
    } else {
      high = mid;
    }
  }

  return low;
}

// Function to insert element in array and shift other elements back
void insert(int list[], int num_index, int pos) {
  int insert_num = list[num_index];
  for (int i = num_index - 1; i >= pos; i--) {
    list[i + 1] = list[i];
  }
  list[pos] = insert_num;
}

// Binary insert sort visualizer
void binary(int list[], int n) {

  // Call drawing library (SDL2)
  if (SDL_Init(SDL_INIT_VIDEO) == 0) {
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    // Create window for SDL2 to draw
    if (SDL_CreateWindowAndRenderer(1280, 720, 0, &window, &renderer) == 0) {

      // 100px padding on 4 sides of window
      int start_x = 100;
      int end_x = 1180;
      int start_y = 620; // y axis is upside down
      int end_y = 100;

      // Finding maximum value within array of numbers
      int max_num = 0;
      for (int i = 0; i < n; i++) {
        max_num = max(max_num, list[i]);
      }

      // Increments for drawing rectangle bars representing numbers in array
      double x_increment = (end_x - start_x) / double(n);
      double y_increment = (start_y - end_y) / double(max_num);

      for (int i = 1; i < n; i++) {

        // Binary search for insert position of element i
        int pos = bin_search(list, i);
        // Insert element i at sorted position
        insert(list, i, pos);

        // Draw lines representing sorted and unsorted elements
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

        // Draw bars for sorted elements
        for (int j = 0; j <= i; j++) {

          SDL_Rect bar;
          bar.x = start_x + j * x_increment;
          bar.y = start_y - int(list[j] * y_increment);
          bar.w = x_increment;
          bar.h = int(list[j] * y_increment);
          SDL_RenderFillRect(renderer, &bar);
        }

        // Draw lines for unsorted elements
        for (int j = i + 1; j < n; j++) {
          SDL_Rect bar;
          bar.x = start_x + j * x_increment;
          bar.y = start_y - int(list[j] * y_increment);
          bar.w = x_increment;
          bar.h = int(list[j] * y_increment);
          SDL_RenderFillRect(renderer, &bar);
        }

        // Show frame
        SDL_RenderPresent(renderer);
        // Pause for visual
        SDL_Delay(500);
      }
    }

    // Quit the drawing library
    if (renderer) {
      SDL_DestroyRenderer(renderer);
    }
    if (window) {
      SDL_DestroyWindow(window);
    }
  }
  SDL_Quit();
}

int main() {
  // Sorting method
  // cout << "Sorting method:" << endl;
  // string sort_type;
  // cin >> sort_type;

  // List of numbers
  // cout << "Number of numbers:" << endl;
  // int num_items;
  // cin >> num_items;

  // cout << "Enter list of numbers:" << endl;
  // int iter = num_items;
  // int list[num_items];
  // while (iter--) {
  //   cin >> list[num_items - iter - 1];
  // }

  int num_items = 5;
  int list[] = {100, 800, 250, 30, 72};

  int sorted_list[num_items];
  copy(list, list + num_items, sorted_list);

  binary(list, num_items);
}
