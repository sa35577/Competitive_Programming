for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << diff_grid[i][j] << " ";
            if (diff_grid[i][j] % 2 == 1) {
                tot++;
            }
        }
        cout << endl;
    }
    cout << tot << "\n";