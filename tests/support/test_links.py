from tests.support.links import draw_links


def test_a_seed_draws_the_same_links_each_time() -> None:
    assert draw_links(7, 50) == draw_links(7, 50)
    assert draw_links(7, 50) != draw_links(8, 50)


def test_a_seed_draws_count_links_of_each_kind_without_an_empty_part() -> None:
    links = draw_links(7, 100)
    assert len(links) == 300
    assert all(part for link in links for part in link)
    assert all(b"user" in b"".join(link).lower() for link in links[100:200])
