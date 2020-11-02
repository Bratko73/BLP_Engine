#pragma once
#include <SFML/Graphics.hpp>
const int H = 17;
const int W = 150;

	static sf::String TileMap[H] = {
	"000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
	"0                                                                                                                                                    0",
	"0                                                                                    w                                                               0",
	"0                   w                                  w                   w                                                                         0",
	"0                                      w                                       kk                                                                    0",
	"0                                                                             k  k    k    k                                                         0",
	"0                      c                                                      k      kkk  kkk  w                                                     0",
	"0                                                                       r     k       k    k                                                         0",
	"0                                                                      rr     k  k                                                                   0",
	"0                                                                     rrr      kk                                                                    0",
	"0                    kckck                                           rrrr                                                                            0",
	"0                                      t0                           rrrrr                                                                            0",
	"0G                                     00              t0          rrrrrr            G                                                               0",
	"0           d    g       d             00              00         rrrrrrr                                                                            0",
	"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP",
	"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP",
	"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP",
	};