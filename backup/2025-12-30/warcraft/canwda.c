// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m白鶴[2;37;0m[2;37;0m", ({"wdyi"}));        
        set("gender", "女性");                
        set("long", "這是一隻漂亮的白鶴，翅膀寬闊.....[2;37;0m
它是鐵血武一的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "canwda");
        set("owner_name", "鐵血武一");
        set_temp("owner", "canwda");
        set_temp("owner_name", "鐵血武一");
        ::setup();
}
