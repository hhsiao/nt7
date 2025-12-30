// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m張[1;31m曼[1;32m玉[2;37;0m[2;37;0m", ({"zhangmanyu"}));        
        set("gender", "女性");                
        set("long", "張曼玉（Maggie Cheung，1964年9月20日-）[2;37;0m
它是無藥可救的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "blkb");
        set("owner_name", "無藥可救");
        set_temp("owner", "blkb");
        set_temp("owner_name", "無藥可救");
        ::setup();
}
