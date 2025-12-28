// This program is a part of NITAN MudLIB

#include <ansi.h>

inherit VRM_SERVER;

#define ENTER_ROOM_X  10000
#define ENTER_ROOM_Y  10000
#define ENTER_ROOM_Z  10000

void create() 
{ 
        // 迷宮房間所繼承的物件的檔案名稱。 
        set_inherit_room( ROOM );  
                        
        //唯一房間
        set_unique_room( ({
                "/maze/necropolis/unique_room/skeleton_room",
                "/maze/necropolis/unique_room/ghost_room",
                "/maze/necropolis/unique_room/zombie_room",
                "/maze/necropolis/unique_room/rest_room",
                "/maze/necropolis/unique_room/quest_room",
        }) ); 

        //迷宮房間裡的怪物。 
        set_maze_npcs( ([
                "/maze/necropolis/npc/skeleton": !random(3),  
                "/maze/necropolis/npc/skeleton_fighter": !random(5),
                "/maze/necropolis/npc/skeleton_mage": !random(5),
                "/maze/necropolis/npc/zombie": !random(3),  
                "/maze/necropolis/npc/zombie_blood": !random(5),
                "/maze/necropolis/npc/zombie_power": !random(5),
                "/maze/necropolis/npc/ghost": !random(3),  
                "/maze/necropolis/npc/ghost_fire": !random(5),
                "/maze/necropolis/npc/ghost_eye": !random(5),
        ]) );        
        //不算死亡                
        //set_maze_nodeath(1);

        set_lonely_create(1);
        
        set_maze_boxs(5);
        //迷宮的單邊長 
        set_maze_long(10); 
                        
        //入口方向(出口在對面) 
        set_entry_dir("north"); 
                        
        //入口與區域的連接方向 
        set_link_entry_dir("north"); 
                        
        //入口與區域的連接檔案名 
        set_link_entry_room(__DIR__"enter"); 
                        
        //出口與區域的連接方向 
        set_link_exit_dir("south"); 
                        
        //出口與區域的連接檔案名 
        set_link_exit_room(__DIR__"leave"); 
                        
        //以下是入口座標
        set_link_entry_room_x(ENTER_ROOM_X);
        set_link_entry_room_y(ENTER_ROOM_Y);
        set_link_entry_room_z(ENTER_ROOM_Z);
                        
        //普通房間描述
        set_maze_room_short(RED "詭異墓園" NOR);
                        
        set_maze_room_desc(@LONG
墓園裡沒有一點生氣，地上到處是枯枝敗葉，偶爾看到一些
乾枯的動物屍骸，讓人不寒而慄，到處散發著一股屍首腐爛的
味道，看不到一絲活物存在。
LONG); 
                        
        //入口房間短描述 
        set_entry_short(HIR "詭異墓園入口" NOR); 
                        
        //入口房間描述 
        set_entry_desc(@LONG
墓園裡沒有一點生氣，地上到處是枯枝敗葉，偶爾看到一些
乾枯的動物屍骸，讓人不寒而慄，到處散發著一股屍首腐爛的
味道，看不到一絲活物存在。
LONG); 
                        
        //出口房間短描述 
        set_exit_short(HIW "詭異墓園出口" NOR); 
                        
        //出口房間描述 
        set_exit_desc(@LONG
墓園裡沒有一點生氣，地上到處是枯枝敗葉，偶爾看到一些
乾枯的動物屍骸，讓人不寒而慄，到處散發著一股屍首腐爛的
味道，看不到一絲活物存在。
LONG); 

        // 迷宮房間是否為戶外房間？ 
        set_outdoors(1); 
        
        set_maze_refresh(600); 
        set_remove_time(1800); 
                                                
} 

