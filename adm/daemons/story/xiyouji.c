// story:laojun

#include <ansi.h>

string give_gift();
mixed *story = ({
    "觀音：  孫悟空，你這個畜牲，你本來答應如來佛祖護送你師傅唐三藏",
    "        去取西經，你居然跟牛魔王串通起來要吃你師傅，你知不知道",
    "        你犯了彌天大罪？",
    "孫悟空：少羅嗦！你追了我三天三夜，因為你是女人我才不殺你，不要",
    "        以為我怕了你了！",
    "唐僧：  悟空，你怎麼可以這樣跟觀音姐姐講話呢？",
    "悟空：  譁！不要吵！",
    "唐僧：  你又在嚇我！",
    "觀音：  你不是怕我又為什麼要打傷紫霞仙子搶走她的月光寶盒，你不",
    "        就是想躲開我嗎？",
    "悟空：  既然躲不了那老孫就跟你絕一死戰！",
    "       (悟空將月光寶盒隨手一拋，正好砸在某人頭上。)",
    (: give_gift :),
    "唐僧：  又幹什麼？",
    "        (倆人正要動手，突然……)",
    "唐僧：  喂喂喂！大家不要生氣，生氣會犯了嗔戒的！悟空你也太調皮",
    "        了，我跟你說過叫你不要亂扔東西，你怎麼又…你看我還沒說",
    "        完你又把棍子給扔掉了！月光寶盒是寶物，你把他扔掉會汙染",
    "        環境，要是砸到小朋友怎麼辦？就算砸不到小朋友砸到那些花",
    "        花草草也是不對的！",
    "        (悟空一把抓住唐僧手中的月光寶盒)",
    "唐僧：  幹什麼？",
    "悟空：  放手！",
    "唐僧：  你想要啊？悟空，你要是想要的話你就說話嘛，你不說我怎麼",
    "        知道你想要呢，雖然你很有誠意地看著我，可是你還是要跟我",
    "        說你想要的。你真的想要嗎？那你就拿去吧！你不是真的想要",
    "        吧？難道你真的想要嗎？……",
    "        悟空：我Kao！",
    "         (悟空一拳將唐僧打倒。)"
});


void create() {
    seteuid(getuid());
}

mixed query_story_message(int step) {
    return step < sizeof(story) ? story[step] : 0;
}

string give_gift() {

    int i;
    object env, ob;
    object *players;
    string msg;

    players = users();
    if (sizeof(players) >= 10)
    {
        for (i = 0; i < 10; i++)
        {
            ob = players[random(sizeof(players))];
            if (wizardp(ob)) continue;
            if (ob->is_fighting()) continue;
            if (!environment(ob)) continue;
            if (ob->query_temp("netdead")) continue;


        }
        if(!ob) return "";
        tell_object(ob, "你突然覺的頭上一陣疼痛，原來月光寶砸中你了雜\n");
        if(random(3)==0)
            ob->unconcious();
        msg = "天上掉了一個盒子，將"+ob->name() + "給砸暈了.......\n";
        env = environment(ob);
        if (objectp(env))
            tell_room(env, msg);
    }

    CHANNEL_D->do_channel(this_object(), "rumor", HIM"好像有人被砸暈了....................\n"NOR);
    return HIM "好像有人被砸暈了....................\n" NOR;
}
