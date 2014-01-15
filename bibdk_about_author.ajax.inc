<?php
/**
 * @file
 * bibdk_about_author.ajax.inc
 */

/**
 * Return json object from ajax call
 */
function bibdk_about_author_ajax_get_about_author() {

  if ( empty($_REQUEST['query']) ) {
    $data['error'] = t('bibdk_about_author_empty_query_error', array(), array('context' => 'bibdk_about_author'));
    watchdog('bibdk_about_author', 'bibdk_about_author: empty query error');
  }
  else {
    $result = bibdk_about_author_get_about_author($_REQUEST['query']);
  }

  $data['query'] = $_REQUEST['query'];

  if ( !$result ) {
    $data['error'] = 'bibdk_about_author_no_records'; // nb: don't translate!
  }
  else {
    $data['list'] = drupal_render(bibdk_about_author_get_link_list_view($result));
  }
  drupal_json_output($data);
}
