// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m冰鳳之舞[2;37;0m[2;37;0m", ({"phx"}));        
        set("gender", "女性");                
        set("long", "雪白的鳳，翱翔於九天之上的聖靈！[2;37;0m
它是慕容飛雪的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "kimib");
        set("owner_name", "慕容飛雪");
        set_temp("owner", "kimib");
        set_temp("owner_name", "慕容飛雪");
        ::setup();
}
