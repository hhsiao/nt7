# Zone Coordinate Layout Tracker

Track progress of assigning x, y, z, length, width, height to all rooms.
Coords go into `graph_mapd.c` `manual_coords` mapping.

## Status Legend
- [x] Complete
- [~] Partial (some rooms done)
- [ ] Not started

## Zones by Size (descending)

### Large (100+ rooms)
- [~] **city** — 166 rooms (157 done in manual_coords)
- [ ] **dali** — 235 rooms
- [ ] **luoyang** — 189 rooms
- [ ] **beijing** — 184 rooms
- [ ] **shaolin** — 174 rooms
- [ ] **changan** — 166 rooms
- [ ] **shenlong** — 148 rooms
- [ ] **hangzhou** — 140 rooms
- [x] **xiangyang** — 136 rooms (135 mapped, wall.c is base class not a room)
- [ ] **mingjiao** — 135 rooms
- [ ] **jingzhou** — 128 rooms
- [ ] **yanziwu** — 120 rooms
- [ ] **suzhou** — 120 rooms
- [ ] **huanggong** — 120 rooms
- [x] **wudang** — 119 rooms (118 mapped, 1 dead room skipped)
- [ ] **tangmen** — 117 rooms
- [ ] **gaoli** — 117 rooms
- [ ] **quanzhen** — 116 rooms
- [ ] **yaowang** — 111 rooms
- [ ] **xiakedao** — 111 rooms
- [ ] **wudu** — 108 rooms
- [ ] **huashan** — 108 rooms
- [ ] **henshan** — 108 rooms
- [ ] **baituo** — 104 rooms
- [ ] **emei** — 102 rooms

### Medium (50–99 rooms)
- [ ] **quanzhou** — 99 rooms
- [ ] **gumu** — 98 rooms
- [ ] **kaifeng** — 96 rooms
- [ ] **kunlun** — 95 rooms
- [ ] **heimuya** — 95 rooms
- [ ] **xingxiu** — 91 rooms
- [ ] **penglai** — 86 rooms
- [ ] **zhongzhou** — 85 rooms
- [ ] **chengdu** — 84 rooms
- [ ] **taohua** — 81 rooms
- [ ] **taishan** — 81 rooms
- [ ] **yueyang** — 80 rooms
- [ ] **lingxiao** — 78 rooms
- [ ] **wuyi** — 69 rooms
- [ ] **tiezhang** — 69 rooms
- [ ] **fuzhou** — 69 rooms
- [ ] **lingzhou** — 68 rooms
- [ ] **guanwai** — 67 rooms
- [ ] **wuxi** — 66 rooms
- [ ] **death** — 63 rooms
- [ ] **lingjiu** — 62 rooms
- [ ] **shouxihu** — 61 rooms
- [ ] **annan** — 59 rooms
- [ ] **jueqing** — 57 rooms
- [ ] **guiyun** — 57 rooms
- [ ] **binghuo** — 56 rooms
- [ ] **kunming** — 55 rooms
- [ ] **songshan** — 53 rooms
- [ ] **city2** — 52 rooms
- [ ] **yanping** — 51 rooms
- [ ] **mobei** — 51 rooms
- [ ] **gaibang** — 51 rooms
- [ ] **shenfeng** — 50 rooms

### Small (20–49 rooms)
- [ ] **heizhao** — 49 rooms
- [ ] **huijiang** — 46 rooms
- [ ] **meizhuang** — 45 rooms
- [ ] **llszhuang** — 45 rooms
- [ ] **shiliang** — 44 rooms
- [ ] **ruzhou** — 43 rooms
- [ ] **huangshan** — 42 rooms
- [ ] **xiaoyao** — 41 rooms
- [ ] **hasake** — 40 rooms
- [ ] **wuguan** — 39 rooms
- [ ] **moon** — 39 rooms
- [ ] **yuanyue** — 38 rooms
- [ ] **xueshan** — 37 rooms
- [ ] **qingcheng** — 37 rooms
- [ ] **jiaxing** — 37 rooms
- [ ] **hanzhong** — 37 rooms
- [ ] **dragon** — 36 rooms
- [ ] **changcheng** — 35 rooms
- [x] **hengshan** — 34 rooms (all 108 mapped, tracker count was wrong)
- [ ] **huanghe** — 33 rooms
- [ ] **gaochang** — 33 rooms
- [ ] **yubifeng** — 32 rooms
- [ ] **foshan** — 32 rooms
- [ ] **village** — 30 rooms
- [ ] **wanjiegu** — 29 rooms
- [ ] **lanzhou** — 29 rooms
- [ ] **beihai** — 29 rooms
- [ ] **wuchang** — 28 rooms
- [ ] **baihuagu** — 28 rooms
- [ ] **hudie** — 27 rooms
- [ ] **yongdeng** — 25 rooms
- [ ] **xuedao** — 24 rooms
- [ ] **tianlongsi** — 24 rooms
- [ ] **taiwan** — 24 rooms
- [ ] **yixing** — 23 rooms
- [ ] **qilian** — 22 rooms
- [ ] **nanyang** — 22 rooms
- [ ] **wuliang** — 20 rooms

### Tiny (<20 rooms)
- [ ] **newbie** — 19 rooms
- [ ] **jianzhong** — 18 rooms
- [ ] **northft** — 17 rooms
- [ ] **qilindong** — 14 rooms
- [ ] **pk** — 14 rooms
- [ ] **xuanminggu** — 13 rooms
- [ ] **motianya** — 10 rooms
- [ ] **register** — 8 rooms
- [ ] **reborn** — 8 rooms
- [ ] **item** — 8 rooms
- [ ] **wizard** — 7 rooms
- [ ] **war** — 2 rooms
- [ ] **dongtian** — 2 rooms
- [ ] **room** — 1 rooms

---

**Total: 7,136 rooms across 110 zones**

## Inter-Zone Links
After individual zones are done, link them together by mapping cross-zone exits.
- [ ] Survey all cross-zone exits
- [ ] Assign zone-level offsets so zones tile correctly in world space
