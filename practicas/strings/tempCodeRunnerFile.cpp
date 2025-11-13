int pal1, pal2, ini1 = 0, fin1 = 2, ini2 = 4, fin2 = 6;
    if(ini1 > 0) pal1 = (h[fin1] - h[ini1 - 1] * p[fin1 - ini1 + 1]) % b;
    else pal1 = h[fin1];
    if(ini2 > 0) pal2 = (h[fin2] - h[ini2 - 1] * p[fin2 - ini2 + 1]) % b;
    else pal2 = h[fin2];

    cout << pal1 << ' ' << pal2 << '\n';