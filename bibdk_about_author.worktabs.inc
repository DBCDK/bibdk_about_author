<?php

/**
 * Implements hook_worktabs_items().
 *
 * @param $tabs
 * @param bibdkWork $entity
 */
function bibdk_about_author_worktabs_items($tabs, $entity) {

  $about_authors = urlencode(serialize($entity->getAboutAuthor()));

  $tabs['more-about']['about-author'] = array(
    'title' => t('bibdk_about_authors', array(), array('context' => 'bibdk_about_author')),
    'btn_txt_closed' => t('view_more', array(), array('context' => 'bibdk_about_author')),
    'rendered' => bibdk_about_author_get_worktab_content($about_authors),
    'weight' => 20,
  );
  return $tabs;

}



/**
 * @param string $query
 * @return array $items
 */
function bibdk_about_author_get_worktab_content($query){

  $items['about_author'] = array(
    '#type' => 'fieldset',
    '#attributes' => array(
      'class' => array('about-author-load'),
      'data-query' => $query,
    ),
    '#attached' => array(
      'js' => array(drupal_get_path('module', 'bibdk_about_author') . '/js/bibdk_about_author.js'),
    ),
  );

  return drupal_render($items);
}



/**
 * Return a list of links from a list of manifestations
 *
 * @param $pids
 * @return string html formatted list of links
 */
function bibdk_about_author_get_link_list_view($queries, $target = '_self') {

  if ( empty($queries) ) {
    return null;
  }

  foreach ( $queries as $id => $query ) {

    $links[] = array(
      'title' => t("bibdk_about_author_read @display", array('@display' => $query['display']), array('context' => 'bibdk_about_author')),
      'href'  => 'search/work/' . $query['searchCode'],
      'attributes' => array(
        'target' => $target,
        'title' => $query['display'],
      )
    );
  }

  return theme('links', array(
    'links' => $links,
  ));

}
