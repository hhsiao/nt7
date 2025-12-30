// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;33m好聲音[1;31m座椅[2;37;0m[2;37;0m", ({"baima"}));        
        set("gender", "男性");                
        set("long", "這個是從英國空運來的好聲音豪華轉椅，犀牛皮做成，價值80多萬。[2;37;0m
它是汪峰的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "wangfeng");
        set("owner_name", "汪峰");
        set_temp("owner", "wangfeng");
        set_temp("owner_name", "汪峰");
        ::setup();
}
