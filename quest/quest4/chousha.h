mapping menpai1=([
        "玄慈大師":   "少林派",
        "宋遠橋":     "武當派",
        "滅絕師太":   "峨嵋派",
        "洪七公":     "丐幫",
        "岳不群":     "華山派",
        "張無忌":     "明教",
        "小龍女":     "古墓派",
        "丘處機":     "全真教",
        //"陳近南":     "雲龍門",
]);

mapping menpai2=([
        "丁春秋":     "星宿派",
        "洪安通":     "神龍教",
        "何鐵手":     "五毒教",
        "歐陽峰":     "歐陽世家",
        "慕容復":     "慕容世家",
        //"邀月宮主":   "移花宮",
        "蘇星河":     "逍遙派",
        "天山童姥":   "靈鷲宮",
        //"黃藥師":     "桃花島",
        "唐老太太":   "唐門世家",
]);

string *master1=({
        "玄慈大師",
        "宋遠橋",
        "滅絕師太",
        "洪七公",
        "岳不群",
        "張無忌",
        "小龍女",
        "丘處機",
        //"陳近南",
});

string *master2=({
        "丁春秋",
        "洪安通",
        "何鐵手",
        "歐陽峰",
        "慕容復",
        //"邀月宮主",
        "蘇星河",
        "天山童姥",
        //"黃藥師",
        "唐老太太",
});

nosave string fam1;
nosave string fam2;

int chousha_begin()
{
        int i,j,k;
        object *ulist;


        i=random(sizeof(master1));
        j=random(sizeof(master2));
        ulist=users();
        k=sizeof(ulist);

        fam1=menpai1[master1[i]];
        fam2=menpai2[master2[j]];

        CHANNEL_D->channel_broadcast("mess", master1[i]+"："+fam1+"門下弟子聽令，命你們在一個時辰內將"+fam2+"徹底擊潰，以匡武林正義！");
        CHANNEL_D->channel_broadcast("mess", master2[j]+"："+fam2+"弟子聽令，命你們在一個時辰內將"+fam1+"徹底蕩平，讓他們嚐嚐我們的厲害！");

        while (k-- )
        {
                if ( !environment(ulist[k]) ) continue;

                if (ulist[k]->query_family() == fam1)
                        set_temp("chousha/fam",fam2,ulist[k]);
                else if (ulist[k]->query_family() == fam2)
                        set_temp("chousha/fam",fam1,ulist[k]);
        }
        set_temp("chousha/fam1",fam1,this_object());
        set_temp("chousha/fam2",fam2,this_object());
        write_file("/quest/quest4/fam1",fam1,1);
        write_file("/quest/quest4/fam2",fam2,1);

        call_out("chousha_close", 1800);
        return 1;
}


void chousha_close()
{
        object *ulist;
        int k;

        ulist=users();
        k=sizeof(ulist);

        while (k--)
        {
                if ( !environment(ulist[k]) ) continue;
                if (query_temp("chousha",ulist[k]))
                {
                        delete_temp("chousha",ulist[k]);
                        tell_object(ulist[k], BLINK"忽然你心中生起一股厭倦的感覺，"
                                                   "開始疑惑的這樣的江湖仇殺有何意義，\n"
                                                   "你看著自己沾滿鮮血的手，開始不斷地問自己為什麼？為什麼？.....\n"NOR);
                }
        }

        CHANNEL_D->channel_broadcast("mess", "歷時半月的"+fam1+"與"+fam2+"之間的仇殺終於結束了，雙方皆死傷無數！");
        delete_temp("chousha",this_object());

        return;
}
