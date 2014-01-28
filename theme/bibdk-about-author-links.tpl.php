<?php
/*
 * Template for bibdk "about author" links
 */

foreach ( $about_author_links as $id => $link ) {
  $title = t("bibdk_about_author_read @display", array('@display' => $link['#title']), array('context' => 'bibdk_about_author'));
  $about_author_links[$id]['#title'] = $title;
  $about_author_links[$id]['#options']['title'] = $title;
}

?>

<div class="about-author-links">
  <?php echo render($about_author_links); ?>
</div>