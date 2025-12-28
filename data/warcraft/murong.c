// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m虞珞[2;37;0m[2;37;0m", ({"pony"}));        
        set("gender", "女性");                
        set("long", "集勇氣、智慧、與美麗於一身的強大生物[2;37;0m
它是慕容雪的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "murong");
        set("owner_name", "慕容雪");
        set_temp("owner", "murong");
        set_temp("owner_name", "慕容雪");
        ::setup();
}
