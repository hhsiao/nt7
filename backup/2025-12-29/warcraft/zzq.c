// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小花貓[2;37;0m[2;37;0m", ({"zzqq"}));        
        set("gender", "男性");                
        set("long", "這是一隻變異的小貓咪[2;37;0m
它是死啦死啦的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "zzq");
        set("owner_name", "死啦死啦");
        set_temp("owner", "zzq");
        set_temp("owner_name", "死啦死啦");
        ::setup();
}
