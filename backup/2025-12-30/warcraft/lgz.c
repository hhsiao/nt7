// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m輸出文字中[2;37;0m[2;37;0m", ({"bmw"}));        
        set("gender", "男性");                
        set("long", "bmw[2;37;0m
它是離歌易趣的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "lgz");
        set("owner_name", "離歌易趣");
        set_temp("owner", "lgz");
        set_temp("owner_name", "離歌易趣");
        ::setup();
}
