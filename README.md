# libtprint

[![Build Status](https://travis-ci.org/wizzard/libtprint.png?branch=master)](https://travis-ci.org/wizzard/libtprint)

TPrint is a simple C library to print ASCII tabular data.

Installation
============
```
sh autogen.sh
./configure
make
make install
```

Usage
=====

(check test_tprint.c for example)

```
#include <tprint.h>
..
TPrint *tp;
tp = tprint_create (..);
tprint_column_add (tp, ..);
..
tprint_data_add_double (tp, ..);
..
tprint_print (tp);
tprint_free (tp);
```

compile:
```
gcc main.c -ltprint `pkg-config --libs --cflags glib-2.0`
```

output example:

```
 ==================================================================================
|             |   Align left   |    Align right     |      1      |  Align center  |
 ==================================================================================
|      msadr  |  80.976        |           338.724  |  1064       |       9        |
|    wofrxty  |  161.952       |          1016.172  |  2128       |       27       |
|      anmir  |  323.904       |          3048.516  |  4256       |       81       |
|       hfmw  |  647.808       |          9145.548  |  8512       |      243       |
|          e  |  1295.616      |         27436.644  |  17024      |      729       |
|         va  |  2591.232      |         82309.932  |  34048      |      2187      |
|    yxqiqhw  |  5182.464      |        246929.796  |  68096      |      6561      |
|  yxlhpresq  |  10364.928     |        740789.388  |  136192     |     19683      |
|      rajle  |  20729.856     |       2222368.164  |  272384     |     59049      |
|         ct  |  41459.712     |       6667104.492  |  544768     |     177147     |
|     drgqar  |  82919.424     |      20001313.476  |  1089536    |     531441     |
|       upmc  |  165838.848    |      60003940.428  |  2179072    |    1594323     |
|    ijuheuw  |  331677.696    |     180011821.284  |  4358144    |    4782969     |
|         hp  |  663355.392    |     540035463.852  |  8716288    |    14348907    |
|    spsawrq  |  1326710.784   |    1620106391.556  |  17432576   |    43046721    |
|        hkr  |  2653421.568   |    4860319174.668  |  34865152   |   129140163    |
|  mnhpctgvl  |  5306843.136   |   14580957524.004  |  69730304   |   387420489    |
|   ofphyald  |  10613686.272  |   43742872572.012  |  139460608  |   1162261467   |
|        hpd  |  21227372.544  |  131228617716.036  |  278921216  |   -808182895   |
|         uu  |  42454745.088  |  393685853148.108  |  557842432  |   1870418611   |
 ==================================================================================
```
