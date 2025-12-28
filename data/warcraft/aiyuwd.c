// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m血鳥[2;37;0m[2;37;0m", ({"aiyuwdzq"}));        
        set("gender", "男性");                
        set("long", "渾身是血的小鳥，一看就是常被人欺負的樣子……[2;37;0m
它是愛心絕情的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "aiyuwd");
        set("owner_name", "愛心絕情");
        set_temp("owner", "aiyuwd");
        set_temp("owner_name", "愛心絕情");
        ::setup();
}
